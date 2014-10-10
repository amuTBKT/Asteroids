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
}

Camera::~Camera() {
}

