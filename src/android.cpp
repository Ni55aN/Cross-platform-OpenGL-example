#include <stdio.h>
#include <jni.h>

#include <EGL/egl.h>
#include "GLES2/gl2.h"


#include <strings.h>
#include <android/log.h>

#define LOG_TAG "NDK LOG"
#define LOG_INFO(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOG_ERROR(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)


float red = 0.0f;

extern "C" {

JNIEXPORT void JNICALL Java_com_ni55an_opengl_1example_NativeOpenGLSurface_nativeStart(JNIEnv* jenv, jobject obj)
{
	eglSwapInterval(eglGetCurrentDisplay(), 0);
	LOG_INFO("onSJava_com_ni55an_opengl_example_NativeOpenGLSurface_nativeStart");
}

JNIEXPORT void JNICALL Java_com_ni55an_opengl_1example_NativeOpenGLSurface_nativePause(JNIEnv* jenv, jobject obj)
{
	LOG_INFO("Java_com_ni55an_opengl_example_NativeOpenGLSurface_nativePause");
}

JNIEXPORT void JNICALL Java_com_ni55an_opengl_1example_NativeOpenGLSurface_nativeResume(JNIEnv* jenv, jobject obj)
{
	LOG_INFO("oJava_com_ni55an_opengl_example_NativeOpenGLSurface_nativeResume");
}

JNIEXPORT void JNICALL Java_com_ni55an_opengl_1example_NativeOpenGLSurface_nativeStop(JNIEnv* jenv, jobject obj)
{
	LOG_INFO("onStJava_com_ni55an_opengl_example_NativeOpenGLSurface_nativeStop");
}


JNIEXPORT void JNICALL Java_com_ni55an_opengl_1example_NativeOpenGLSurface_nativeResize(JNIEnv* jenv, jobject obj, jint w, jint h)
{
	LOG_INFO("onStJava_com_ni55an_opengl_example_NativeOpenGLSurface_nativeResize");
}

JNIEXPORT void JNICALL Java_com_ni55an_opengl_1example_NativeOpenGLSurface_nativeRender(JNIEnv* jenv, jobject obj)
{
	red=red>1.0f?0:red+0.03f;

	glClearColor(red,0.8f,0.5f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	//LOG_INFO("Java_com_ni55an_opengl_example_NativeOpenGLSurface_nativeRender");
}

JNIEXPORT void JNICALL Java_com_ni55an_opengl_1example_NativeOpenGLSurface_nativeDown(JNIEnv* jenv, jobject obj, jint id, jfloat x, jfloat y)
{
	LOG_INFO("Java_com_ni55an_opengl_example_NativeOpenGLSurface_nativeDown");
}

JNIEXPORT void JNICALL Java_com_ni55an_opengl_1example_NativeOpenGLSurface_nativeMove(JNIEnv* jenv, jobject obj,  jint id, jfloat x, jfloat y)
{
	LOG_INFO("Java_com_ni55an_opengl_example_NativeOpenGLSurface_nativeMove");
}

JNIEXPORT void JNICALL Java_com_ni55an_opengl_1example_NativeOpenGLSurface_nativeUp(JNIEnv* jenv, jobject obj,  jint id, jfloat x, jfloat y)
{
	LOG_INFO("Java_com_ni55an_opengl_1example_NativeOpenGLSurface_nativeUp");
}


JNIEXPORT void JNICALL Java_com_ni55an_opengl_1example_NativeOpenGLSurface_nativeKeyDown(JNIEnv* jenv, jobject obj, jint keycode, jboolean ctrl, jboolean alt, jboolean shift)
{
	LOG_INFO("Java_com_ni55an_opengl_1example_NativeOpenGLSurface_nativeKeyDown");
}

JNIEXPORT void JNICALL Java_com_ni55an_opengl_1example_NativeOpenGLSurface_nativeKeyUp(JNIEnv* jenv, jobject obj,  jint keycode, jboolean ctrl,  jboolean alt, jboolean shift)
{
	LOG_INFO("Java_com_ni55an_opengl_1example_NativeOpenGLSurface_nativeKeyUp");
}


}
