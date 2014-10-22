#include <jni.h>

#include <GLES/gl.h>
#include "controller/GameController.h"
#include "core/GLOBALVAR.h"

jint JNI_OnLoad(JavaVM* pVM, void* resource);
void nativeSurfaceCreated(JNIEnv* env, jclass clazz);
void nativeDrawFrame(JNIEnv* env, jclass clazz);
void nativeOnTouchEvent(JNIEnv* env, jclass clazz, int);
void nativeSurfaceChanged(JNIEnv* env, jclass clazz, int width, int height);

// gameplay variables
int GLOBAL_VAR::SCREEN_WIDTH, GLOBAL_VAR::SCREEN_HEIGHT;
bool GLOBAL_VAR::debugPhysics = true;
Camera* GLOBAL_VAR::camera;
Ship* GameController::ship;
float GameController::shipNSpeed = 5, GameController::shipBSpeed = 1.5;
MeteoroidManager* GameController::meteoroidManager;
ExplosionManager* MeteoroidManager::expManager;

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
	if (i == 3) {
		GameController::ship->shoot();
//		GameController::meteoroidManager->genCirclePattern(Vector2(400, 240));
	}
	if (i == 1) GameController::ship->transform.velocity.rotate(3);
	if (i == 2) GameController::ship->transform.velocity.rotate(-3);
	if (i == 4) {
		GameController::slowShip();
	}
	if (i == 5) {
		GameController::accelerateShip();
	}
}

void nativeSurfaceCreated(JNIEnv* env, jclass clazz){
	glDisable(GL_DITHER);
	glClearColor(0, 0, 0, 1);

	GameController::init();

	Ship ship(10);
	ship.transform.setPosition(Vector2(50, 240));
	ship.transform.setVelocity(Vector2(5, 0));
	GameController::setShip(ship);

	GameController::meteoroidManager-> genNewMeteoroid(1, Vector2(-100, 240), Vector2(1.5, 0));
}

void nativeDrawFrame(JNIEnv* env, jclass clazz){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	GameController::update();
}

void nativeSurfaceChanged(JNIEnv* env, jclass clazz, int width, int height){
	GameController::updateCamera(width, height);
}
