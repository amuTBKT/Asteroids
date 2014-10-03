package com.amu.asteroids;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

import android.opengl.GLSurfaceView.Renderer;

public class CustomRenderer implements Renderer {

	public void onSurfaceCreated(GL10 gl, EGLConfig egl) {
		nativeSurfaceCreated();
	}
	
	public void onDrawFrame(GL10 gl) {
		nativeDrawFrame();
	}

	public void onSurfaceChanged(GL10 gl, int width, int height) {
		nativeSurfaceChanged(width, height);
	}
	
	// native methods
	private static native void nativeSurfaceCreated();
	private static native void nativeDrawFrame();
	private static native void nativeSurfaceChanged(int width, int height);

	static {
		System.loadLibrary("Asteroids");
	}
	
}
