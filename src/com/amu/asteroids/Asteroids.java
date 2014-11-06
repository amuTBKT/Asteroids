package com.amu.asteroids;

import android.app.Activity;
import android.opengl.GLSurfaceView;
import android.os.Bundle;
import android.util.DisplayMetrics;
import android.view.MotionEvent;
import android.view.View;
import android.view.View.OnClickListener;
import android.view.View.OnTouchListener;
import android.view.ViewGroup;
import android.view.Window;
import android.view.WindowManager;
import android.widget.Button;

public class Asteroids extends Activity implements OnClickListener, OnTouchListener {

	GLSurfaceView glSurfaceView;
	CustomRenderer renderer;
	Button fireButton, rCWButton, rCCWButton, brakeButton;
	int ACTION_SHOOT = 3, ACTION_ROTATE_CW = 2, ACTION_ROTATE_CCW = 1, ACTION_ACCELERATE = 4;
	
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		
		// making the application full screen
		requestWindowFeature(Window.FEATURE_NO_TITLE);
		getWindow().setFlags(WindowManager.LayoutParams.FLAG_FULLSCREEN, WindowManager.LayoutParams.FLAG_FULLSCREEN);
		
		// opengl setup
		glSurfaceView = new GLSurfaceView(this);
		renderer = new CustomRenderer();
		glSurfaceView.setRenderer(renderer);
		glSurfaceView.setPreserveEGLContextOnPause(true);
		setContentView(glSurfaceView);
		
		setButtons();
	}
	
	protected void onPause() {
		glSurfaceView.onPause();
		super.onPause();
	}

	protected void onResume() {
		glSurfaceView.onResume();
		super.onResume();
	}

	private void setButtons(){
//		Display display = getWindowManager().getDefaultDisplay();
//		int width = display.getWidth(), height = display.getHeight();
		
		DisplayMetrics metrics = getResources().getDisplayMetrics();
		int width = metrics.widthPixels, height = metrics.heightPixels;
		
		rCWButton = new Button(this);
		rCWButton.setText(" >> ");
		rCWButton.setOnTouchListener(this);
		rCWButton.setId(ACTION_ROTATE_CW);
		rCWButton.setX(160);
		rCWButton.setY(height - 80);
		addContentView(rCWButton, new ViewGroup.LayoutParams(ViewGroup.LayoutParams.WRAP_CONTENT, ViewGroup.LayoutParams.WRAP_CONTENT));
		
		rCCWButton = new Button(this);
		rCCWButton.setText(" << ");
		rCCWButton.setOnTouchListener(this);
		rCCWButton.setId(ACTION_ROTATE_CCW);
		rCCWButton.setX(40);
		rCCWButton.setY(height - 80);
		addContentView(rCCWButton, new ViewGroup.LayoutParams(ViewGroup.LayoutParams.WRAP_CONTENT, ViewGroup.LayoutParams.WRAP_CONTENT));
		
		fireButton = new Button(this);
		fireButton.setText(" SHOOT ");
		fireButton.setOnClickListener(this);
		fireButton.setId(ACTION_SHOOT);
		fireButton.setX(width - 140);
		fireButton.setY(height - 80);
		addContentView(fireButton, new ViewGroup.LayoutParams(ViewGroup.LayoutParams.WRAP_CONTENT, ViewGroup.LayoutParams.WRAP_CONTENT));

		brakeButton = new Button(this);
		brakeButton.setText(" PADEL ");
		brakeButton.setOnTouchListener(this);
		brakeButton.setId(ACTION_ACCELERATE);
		brakeButton.setX(width - 140);
		brakeButton.setY(height - 160);
		addContentView(brakeButton, new ViewGroup.LayoutParams(ViewGroup.LayoutParams.WRAP_CONTENT, ViewGroup.LayoutParams.WRAP_CONTENT));
	}
	
	public void onClick(View view) {
		renderer.OnTouchEvent(view.getId());
	}

	public boolean onTouch(View view, MotionEvent event) {
		if (view.getId() == 4){
			if (event.getAction() == MotionEvent.ACTION_UP) renderer.OnTouchEvent(5);
			else renderer.OnTouchEvent(view.getId());
		}
		else {
			renderer.OnTouchEvent(view.getId());
		}
		return false;
	}

}
