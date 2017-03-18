mkdir -p build/Web/Debug
cd build/Web/Debug

cmake -DCMAKE_C_COMPILER=emcc -DCMAKE_CXX_COMPILER=em++ -DCMAKE_TOOLCHAIN_FILE=/emsdk_portable/emscripten/tag-1.37.3/cmake/Modules/Platform/Emscripten.cmake  -DCMAKE_BUILD_TYPE=Debug  -G "Unix Makefiles" -DCMAKE_MAKE_PROGRAM=emmake  ../../..

make

