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

public class Asteroids extends ActionBarActivity implements android.view.View.OnClickListener, OnTouchListener {

	GLSurfaceView glSurfaceView;
	CustomRenderer renderer;
	Button fireButton, rCWButton, rCCWButton;
	
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
		
		setButtons();
	}
	
	private void setButtons(){
		rCWButton = new Button(this);
		rCWButton.setText(" > ");
		rCWButton.setOnTouchListener(this);
		rCWButton.setId(2);
		rCWButton.setX(160);
		rCWButton.setY(480 - 80);
		addContentView(rCWButton, new ViewGroup.LayoutParams(ViewGroup.LayoutParams.WRAP_CONTENT, ViewGroup.LayoutParams.WRAP_CONTENT));
		
		rCCWButton = new Button(this);
		rCCWButton.setText(" < ");
		rCCWButton.setOnTouchListener(this);
		rCCWButton.setId(1);
		rCCWButton.setX(40);
		rCCWButton.setY(480 - 80);
		addContentView(rCCWButton, new ViewGroup.LayoutParams(ViewGroup.LayoutParams.WRAP_CONTENT, ViewGroup.LayoutParams.WRAP_CONTENT));
		
		fireButton = new Button(this);
		fireButton.setText(" X ");
		fireButton.setOnClickListener(this);
		fireButton.setId(3);
		fireButton.setX(800 - 100);
		fireButton.setY(480 - 80);
		addContentView(fireButton, new ViewGroup.LayoutParams(ViewGroup.LayoutParams.WRAP_CONTENT, ViewGroup.LayoutParams.WRAP_CONTENT));
	}

	public void onClick(View view) {
		renderer.OnTouchEvent(view.getId());
	}

	public boolean onTouch(View view, MotionEvent event) {
		renderer.OnTouchEvent(view.getId());
		return false;
	}

}
