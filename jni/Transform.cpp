/*
 * Transform.cpp
 *
 *  Created on: Oct 3, 2014
 *      Author: amu
 */

#include "Transform.h"

Transform::Transform(Vector2 pos, Vector2 scl, float rot): position(pos), scale(scl), rotation(rot) {}
Transform::Transform(): position(Vector2(0,0)), scale(Vector2(1, 1)), rotation(0){}

void Transform::setPosition(Vector2 pos){
	position = pos;
}

void Transform::translate(Vector2 dV){
	position += dV;
}

void Transform::translate(float dx, float dy){
	translate(Vector2(dx, dy));
}

void Transform::setScale(Vector2 scl){
	scale = scl;
}

void Transform::changeScale(Vector2 dV){
	scale += dV;
}

void Transform::changeScale(float dx, float dy){
	changeScale(Vector2(dx, dy));
}

void Transform::setRotation(float angle){
	rotation = angle;
}

void Transform::rotate(float da){
	rotation += da;
}

Transform::~Transform() {
}

