#include <jni.h>

#include <GLES/gl.h>
#include "models/Meteoroid.h"
#include "models/Bullet.h"
#include "controller/GameController.h"

jint JNI_OnLoad(JavaVM* pVM, void* resource);
void nativeSurfaceCreated(JNIEnv* env, jclass clazz);
void nativeDrawFrame(JNIEnv* env, jclass clazz);
void nativeSurfaceChanged(JNIEnv* env, jclass clazz, int width, int height);

// gameplay variables
float SCREEN_WIDTH, SCREEN_HEIGHT;
Camera* GameController::camera;
Ship* GameController::ship;
std::vector<MovingEntity> GameController::objects;

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

	Meteoroid meteor1(10);
	meteor1.transform.setPosition(Vector2(50, 240));
	meteor1.transform.setVelocity(Vector2(5, 0));

	Meteoroid meteor2(10);
	meteor2.transform.setPosition(Vector2(750, 240));
	meteor2.transform.setVelocity(Vector2(5, 0));

	Ship ship(10);
	ship.transform.setPosition(Vector2(100, 100));
	ship.transform.setVelocity(Vector2(5, 2));

	Bullet bullet(4, Vector2(5, 0));
	bullet.transform.setPosition(Vector2(10, 240));

	GameController::addBody(meteor1);
	GameController::addBody(meteor2);
	GameController::addBody(ship);
	GameController::addBody(bullet);

}

void nativeDrawFrame(JNIEnv* env, jclass clazz){
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	GameController::update();

}

void nativeSurfaceChanged(JNIEnv* env, jclass clazz, int width, int height){
	SCREEN_WIDTH = width;
	SCREEN_HEIGHT = height;
	glViewport(0, 0, width, height);
	GameController::updateCamera(width, height);
}
