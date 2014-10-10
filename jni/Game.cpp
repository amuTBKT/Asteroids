#include <jni.h>

#include <GLES/gl.h>
#include "models/Meteoroid.h"
#include "models/Camera.h"

jint JNI_OnLoad(JavaVM* pVM, void* resource);
void nativeSurfaceCreated(JNIEnv* env, jclass clazz);
void nativeDrawFrame(JNIEnv* env, jclass clazz);
void nativeSurfaceChanged(JNIEnv* env, jclass clazz, int width, int height);

// gameplay variables
Meteoroid* meteor;
Camera* camera;
float SCREEN_WIDTH, SCREEN_HEIGHT;

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

	meteor = new Meteoroid(10);
	meteor->transform.setPosition(Vector2(400, 240));
	meteor->transform.setVelocity(Vector2(3, 5));
}

void nativeDrawFrame(JNIEnv* env, jclass clazz){
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	meteor->update();

	if (meteor->collider.testAABB(camera->getTopBound()) || meteor->collider.testAABB(camera->getBottomBound())){
		meteor->transform.velocity.y *= -1;
	}

	if (meteor->collider.testAABB(camera->getLeftBound()) || meteor->collider.testAABB(camera->getRightBound())){
		meteor->transform.velocity.x *= -1;
	}
}

void nativeSurfaceChanged(JNIEnv* env, jclass clazz, int width, int height){
	SCREEN_WIDTH = width;
	SCREEN_HEIGHT = height;
	glViewport(0, 0, width, height);
	camera = new Camera(width, height);
	camera->transform.setPosition(Vector2(400, 240));
	camera->update();
}
