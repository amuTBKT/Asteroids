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

bool Collider::inBounds(const Vector2& point){
	return ((point.x >= bounds->minX && point.x <= bounds->maxX) & (point.y >= bounds->minY && point.y <= bounds->maxY));
}

bool Collider::inBounds(float x, float y){
	return inBounds(Vector2(x, y));
}

bool Collider::testAABB(const Collider& collider){
	if (bounds->maxX < collider.bounds->minX) return false;
	if (bounds->minX > collider.bounds->maxX) return false;
	if (bounds->maxY < collider.bounds->minY) return false;
	if (bounds->minY > collider.bounds->maxY) return false;

	// there is an overlap
	return true;
}

BoxCollider::~BoxCollider() {
}

