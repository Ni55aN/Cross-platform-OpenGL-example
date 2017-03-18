mkdir -p build/Linux/Debug
cd build/Linux/Debug

cmake -DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++  -DCMAKE_BUILD_TYPE=Debug  -G "Unix Makefiles" ../../..
make

