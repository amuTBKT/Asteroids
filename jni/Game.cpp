#include <jni.h>

#include <GLES/gl.h>
#include "models/Meteoroid.h"
#include "models/Ship.h"
#include "models/Camera.h"

jint JNI_OnLoad(JavaVM* pVM, void* resource);
void nativeSurfaceCreated(JNIEnv* env, jclass clazz);
void nativeDrawFrame(JNIEnv* env, jclass clazz);
void nativeSurfaceChanged(JNIEnv* env, jclass clazz, int width, int height);

// gameplay variables
Meteoroid *meteor1, *meteor2;
Ship *ship;
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

	meteor1 = new Meteoroid(10);
	meteor1->transform.setPosition(Vector2(50, 240));
	meteor1->transform.setVelocity(Vector2(5, 0));

	meteor2 = new Meteoroid(10);
	meteor2->transform.setPosition(Vector2(750, 240));
	meteor2->transform.setVelocity(Vector2(5, 0));

	ship = new Ship(10);
	ship->transform.setPosition(Vector2(100, 100));
	ship->transform.setVelocity(Vector2(5, 2));
}

void nativeDrawFrame(JNIEnv* env, jclass clazz){
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	meteor1->update();
	meteor2->update();

	ship->update();

	if (meteor1->collider.testAABB(camera->getTopBound()) || meteor1->collider.testAABB(camera->getBottomBound())){
		meteor1->transform.velocity.y *= -1;
	}

	if (meteor1->collider.testAABB(camera->getLeftBound()) || meteor1->collider.testAABB(camera->getRightBound())){
		meteor1->transform.velocity.x *= -1;
	}

	if (meteor2->collider.testAABB(camera->getTopBound()) || meteor2->collider.testAABB(camera->getBottomBound())){
		meteor2->transform.velocity.y *= -1;
	}

	if (meteor2->collider.testAABB(camera->getLeftBound()) || meteor2->collider.testAABB(camera->getRightBound())){
		meteor2->transform.velocity.x *= -1;
	}

	if (ship->collider.testAABB(camera->getTopBound()) || ship->collider.testAABB(camera->getBottomBound())){
		ship->transform.velocity.y *= -1;
	}

	if (ship->collider.testAABB(camera->getLeftBound()) || ship->collider.testAABB(camera->getRightBound())){
		ship->transform.velocity.x *= -1;
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
