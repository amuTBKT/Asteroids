/*
 * Transform.cpp
 *
 *  Created on: Oct 3, 2014
 *      Author: amu
 */

#include "Transform.h"

Transform::Transform(): position(Vector2(0,0)), scale(Vector2(1, 1)), rotation(0){}
Transform::Transform(Vector2 pos, Vector2 scl, float rot): position(pos), scale(scl), rotation(rot) {}
Transform::Transform(const Transform& t){
	Transform(t.position, t.scale, t.rotation);
}

void Transform::setPosition(const Vector2& pos){
	position = Vector2(pos);
}

void Transform::translate(Vector2 dV){
	position += dV;
}

void Transform::translate(float dx, float dy){
	translate(Vector2(dx, dy));
}

void Transform::setScale(const Vector2& scl){
	scale = Vector2(scl);
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

