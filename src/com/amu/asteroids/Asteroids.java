package com.amu.asteroids;

import android.opengl.GLSurfaceView;
import android.os.Bundle;
import android.support.v7.app.ActionBarActivity;
import android.view.Window;
import android.view.WindowManager;

public class Asteroids extends ActionBarActivity {

	GLSurfaceView glSurfaceView;
	
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		
		// making the application full screen
		requestWindowFeature(Window.FEATURE_NO_TITLE);
		getWindow().setFlags(WindowManager.LayoutParams.FLAG_FULLSCREEN, WindowManager.LayoutParams.FLAG_FULLSCREEN);
		
		// opengl setup
		glSurfaceView = new GLSurfaceView(this);
		glSurfaceView.setRenderer(new CustomRenderer());
		setContentView(glSurfaceView);
		
	}

}
