case $1 in
	32) 
	c="i686"
	;;
	64)
	c="x86_64"
	;;
	*)
	echo "please select 32 or 64"
	exit
	;;
esac


mkdir -p build/Windows/x$1/Debug
cd build/Windows/x$1/Debug


cmake  -DWINDOWS=$1 -DCMAKE_SYSTEM_NAME=Windows -DCMAKE_C_COMPILER=$c-w64-mingw32-gcc -DCMAKE_CXX_COMPILER=$c-w64-mingw32-g++  -DCMAKE_BUILD_TYPE=Debug  -G "Unix Makefiles" ../../../..
make

