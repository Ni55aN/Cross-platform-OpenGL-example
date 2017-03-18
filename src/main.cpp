#ifdef __EMSCRIPTEN__
#include "emscripten.cpp"

#elif defined __ANDROID__
#include "android.cpp"

#else
#include "desktop.cpp"

#endif
