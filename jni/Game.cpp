#include <jni.h>

#include <GLES/gl.h>
#include "models/Mesh.h"

jint JNI_OnLoad(JavaVM* pVM, void* resource);
void nativeSurfaceCreated(JNIEnv* env, jclass clazz);
void nativeDrawFrame(JNIEnv* env, jclass clazz);
void nativeSurfaceChanged(JNIEnv* env, jclass clazz, int width, int height);

Mesh mesh;

jint JNI_OnLoad(JavaVM* pVM, void* reserved){
	JNIEnv* env;

	if (pVM->GetEnv(reinterpret_cast<void**>(&env), JNI_VERSION_1_6) != JNI_OK) {
		return -1;
	}

	// native methods
	JNINativeMethod nm[3];
	nm[0].name = "nativeSurfaceCreated";
	nm[0].signature = "()V";
	nm[0].fnPtr = (void*)nativeSurfaceCreated;
	nm[1].name = "nativeDrawFrame";
	nm[1].signature = "()V";
	nm[1].fnPtr = (void*)nativeDrawFrame;
	nm[2].name = "nativeSurfaceChanged";
	nm[2].signature = "(II)V";
	nm[2].fnPtr = (void*)nativeSurfaceChanged;

	jclass cls = env->FindClass("com/amu/asteroids/CustomRenderer");
	// Register methods with env->RegisterNatives.
	env->RegisterNatives(cls, nm, 3);

	return JNI_VERSION_1_6;
}

void nativeSurfaceCreated(JNIEnv* env, jclass clazz){
	glDisable(GL_DITHER);

	float data[] = {-1, 0, 0, 0, 1, 0, 1, 0, 0};
	float colors[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
	mesh.setVertices(data, colors);

//	if (gObj.collider.inBounds(0, 0)){
//		glClearColor(0.3, 0, 0.1, 1);
//	}
//	else {
//		glClearColor(0, 1, 0, 1);
//	}
}

void nativeDrawFrame(JNIEnv* env, jclass clazz){
	glClearColor(0.3, 0, 0.1, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	mesh.render();
}

void nativeSurfaceChanged(JNIEnv* env, jclass clazz, int width, int height){
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	float ratio = (float) width / (float) height;
	glOrthof(-ratio, ratio, -1, 1, 0, 25);
}
