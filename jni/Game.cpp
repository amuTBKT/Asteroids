#include <jni.h>

#include <GLES/gl.h>
#include "controller/GameController.h"
#include "core/GLOBALVAR.h"
#include "models/Hud.h"

jint JNI_OnLoad(JavaVM* pVM, void* resource);
void nativeSurfaceCreated(JNIEnv* env, jclass clazz);
void nativeDrawFrame(JNIEnv* env, jclass clazz);
void nativeOnTouchEvent(JNIEnv* env, jclass clazz, int);
void nativeSurfaceChanged(JNIEnv* env, jclass clazz, int width, int height);

// gameplay variables
int GLOBAL_VAR::SCREEN_WIDTH, GLOBAL_VAR::SCREEN_HEIGHT;
bool GLOBAL_VAR::PAUSE_GAME = false, GLOBAL_VAR::RESUME_GAME = false;
bool GLOBAL_VAR::debugPhysics = false;
Camera* GLOBAL_VAR::camera;
Ship* GameController::ship;
MeteoroidManager* GameController::meteoroidManager;
bool MeteoroidManager::decLife = false;
Hud hud;
int ACTION_SHOOT = 3, ACTION_ROTATE_CW = 2, ACTION_ROTATE_CCW = 1, ACTION_ACCELERATE = 4;

jint JNI_OnLoad(JavaVM* pVM, void* reserved){
	JNIEnv* env;

	if (pVM->GetEnv(reinterpret_cast<void**>(&env), JNI_VERSION_1_6) != JNI_OK) {
		return -1;
	}

	// native methods
	JNINativeMethod nm[4];
	nm[0].name = "nativeSurfaceCreated";
	nm[0].signature = "()V";
	nm[0].fnPtr = (void*)nativeSurfaceCreated;
	nm[1].name = "nativeDrawFrame";
	nm[1].signature = "()V";
	nm[1].fnPtr = (void*)nativeDrawFrame;
	nm[2].name = "nativeSurfaceChanged";
	nm[2].signature = "(II)V";
	nm[2].fnPtr = (void*)nativeSurfaceChanged;
	nm[3].name = "nativeOnTouchEvent";
	nm[3].signature = "(I)V";
	nm[3].fnPtr = (void*)nativeOnTouchEvent;

	jclass cls = env->FindClass("com/amu/asteroids/CustomRenderer");
	// Register methods with env->RegisterNatives.
	env->RegisterNatives(cls, nm, 4);

	return JNI_VERSION_1_6;
}

void nativeOnTouchEvent(JNIEnv* env, jclass clazz, int i){
	if (!GameController::ship->isActive){
		if (i == ACTION_ACCELERATE) {
			GameController::ship->isActive = true;
		}
		return;
	}

	if (i == ACTION_ROTATE_CCW) GameController::ship->transform.velocity.rotate(3);
	if (i == ACTION_ROTATE_CW) GameController::ship->transform.velocity.rotate(-3);
	if (i == ACTION_SHOOT) {
		GameController::ship->shoot();
	}
	if (i == ACTION_ACCELERATE) {
		if (!hud.meter->isEmpty()){
			GameController::slowShip(1.5);
		}
		else {
			GameController::accelerateShip(5);
		}
		hud.meter->startUsingMeter();
	}
	if (i == 5) {
		GameController::accelerateShip(5);
		hud.meter->fillMeter();
	}
}

void nativeSurfaceCreated(JNIEnv* env, jclass clazz){
	glDisable(GL_DITHER);
	glClearColor(0, 0, 0, 1);

	GameController::init();

	Ship ship(10);
	ship.transform.setPosition(Vector2(50, 240));
//	ship.transform.setVelocity(Vector2(5, 0));
	GameController::setShip(ship);
}

void nativeDrawFrame(JNIEnv* env, jclass clazz){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	GameController::update();
	hud.render();
}

void nativeSurfaceChanged(JNIEnv* env, jclass clazz, int width, int height){
	GameController::updateCamera(width, height);
	hud.init();
}
