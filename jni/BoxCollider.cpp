/*
 * BoxCollider.cpp
 *
 *  Created on: Oct 3, 2014
 *      Author: amu
 */

#include "BoxCollider.h"

BoxCollider::BoxCollider() {
	Collider();
}

bool Collider::inBounds(Vector2 point){
	return ((point.x >= bounds->minX && point.x <= bounds->maxX) & (point.y >= bounds->minY && point.y <= bounds->maxY));
}

bool Collider::inBounds(float x, float y){
	return inBounds(Vector2(x, y));
}

BoxCollider::~BoxCollider() {
}

