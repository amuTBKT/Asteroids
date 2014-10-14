package com.amu.asteroids;

import android.opengl.GLSurfaceView;
import android.os.Bundle;
import android.support.v7.app.ActionBarActivity;
import android.view.MotionEvent;
import android.view.View;
import android.view.View.OnTouchListener;
import android.view.ViewGroup;
import android.view.Window;
import android.view.WindowManager;
import android.widget.Button;

public class Asteroids extends ActionBarActivity implements OnTouchListener {

	GLSurfaceView glSurfaceView;
	CustomRenderer renderer;
	Button lButton;
	
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		
		// making the application full screen
		requestWindowFeature(Window.FEATURE_NO_TITLE);
		getWindow().setFlags(WindowManager.LayoutParams.FLAG_FULLSCREEN, WindowManager.LayoutParams.FLAG_FULLSCREEN);
		
		// opengl setup
		glSurfaceView = new GLSurfaceView(this);
		renderer = new CustomRenderer();
		glSurfaceView.setRenderer(renderer);
		setContentView(glSurfaceView);
		
		lButton = new Button(this);
		lButton.setText(" X ");
		lButton.setOnTouchListener(this);
		lButton.setId(4);
		lButton.setX(800 - 100);
		lButton.setY(480 - 80);
		addContentView(lButton, new ViewGroup.LayoutParams(ViewGroup.LayoutParams.WRAP_CONTENT, ViewGroup.LayoutParams.WRAP_CONTENT));
	}

	public boolean onTouch(View view, MotionEvent event) {
		if (view.getId() == 4){
			renderer.OnTouchEvent();
		}
		return false;
	}

}
