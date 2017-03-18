case $1 in
	"x86_64") abi=$1 tool="x86_64-4.9"
	;;
	"x86") abi=$1 tool="x86-4.9"
	;;
	"armeabi-v7a") abi=$1 tool="arm-linux-androideabi-4.9"
	;;
	"armeabi") abi=$1 tool="arm-linux-androideabi-4.9"
	;;
	"arm64-v8a") abi=$1 tool="aarch64-linux-android-4.9"
	;;
	*) echo "abi not allowed"
	exit
	;;
esac

echo "Using ABI=$abi"

mkdir -p build/Android/$abi/Debug
cd build/Android/$abi/Debug

cmake -DANDROID_NDK=/opt/android-ndk-r14 -DANDROID_ABI=$abi -DANDROID_TOOLCHAIN_NAME=$tool -DCMAKE_TOOLCHAIN_FILE=/opt/android-ndk-r14/build/cmake/android.toolchain.cmake -DCMAKE_BUILD_TYPE=Debug  -G "Unix Makefiles" ../../../..

make

