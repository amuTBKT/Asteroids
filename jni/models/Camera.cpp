/*
 * Camera.cpp
 *
 *  Created on: Oct 10, 2014
 *      Author: amu
 */

#include "Camera.h"

Camera::Camera(float w, float h) : width(w), height(h), zNear(0), zFar(5){}

void Camera::update(){
	GameObject::update();

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrthof(transform.position.x - width / 2, transform.position.x  + width / 2, transform.position.y - height / 2, transform.position.y + height / 2, zNear, zFar);

	Collider c; float thickness = 1;
	c.setBounds(thickness, height);c.position.set(transform.position.x - width / 2, transform.position.y);
	screen_bounds[0] = c; // left collider
	c.position.set(transform.position.x + width / 2, transform.position.y);
	screen_bounds[1] = c; // right collider
	c.setBounds(width, thickness);c.position.set(transform.position.x, transform.position.y + height / 2);
	screen_bounds[2] = c; // top collider
	c.position.set(transform.position.x, transform.position.y - height / 2);
	screen_bounds[3] = c; // bottom collider
}

Collider Camera::getLeftBound(){
	return screen_bounds[0];
}

Collider Camera::getRightBound(){
	return screen_bounds[1];
}

Collider Camera::getTopBound(){
	return screen_bounds[2];
}

Collider Camera::getBottomBound(){
	return screen_bounds[3];
}

Camera::~Camera() {
}

