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
Collider screen_bounds[4];

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
	meteor->transform.setVelocity(Vector2(1, 0));

	Collider c;c.setBounds(5, 480);c.position.set(0, 240);
	screen_bounds[0] = c;
	c.position.set(800, 0);
	screen_bounds[1] = c;
	c.setBounds(800, 5);c.position.set(400, 480);
	screen_bounds[2] = c;
	c.position.set(400, 0);
	screen_bounds[3] = c;
}

void nativeDrawFrame(JNIEnv* env, jclass clazz){
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	meteor->update();

	if (meteor->collider.testAABB(screen_bounds[0]) || meteor->collider.testAABB(screen_bounds[1])){
		meteor->transform.velocity.x *= -1;
	}
}

void nativeSurfaceChanged(JNIEnv* env, jclass clazz, int width, int height){
	glViewport(0, 0, width, height);
	camera = new Camera(width, height);
	camera->transform.setPosition(Vector2(400, 240));
	camera->update();
}
