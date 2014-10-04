/*
 * CircleCollider.cpp
 *
 *  Created on: Oct 4, 2014
 *      Author: amu
 */

#include "CircleCollider.h"

CircleCollider::CircleCollider() {
	Collider();
}

void CircleCollider::setRadius(float r){
	bounds->maxX = r;
	bounds->maxY = r;
}

void CircleCollider::translate(const Vector2& dV){
	bounds-> minX+= dV.x;
	bounds-> minY+= dV.y;
}

bool Collider::inBounds(const Vector2& point){
	return (powf(bounds->minX - point.x, 2) + powf(bounds->minY - point.y, 2) <= bounds->maxX * bounds->maxX);
}

bool Collider::inBounds(float x, float y){
	return inBounds(Vector2(x, y));
}

bool Collider::testAABB(const Collider& collider){
	// for circle collider
	return (powf(bounds->minX - collider.bounds->minX, 2) + powf(bounds->minY - collider.bounds->minY, 2) <= powf(bounds->maxX + collider.bounds->maxX, 2));

	// for box collider
	// return (powf(bounds->minX - (collider.bounds->maxX - collider.bounds->minX) / 2, 2) + powf(bounds->minY - (collider.bounds->maxY - collider.bounds->minY) / 2, 2) <= powf(bounds->maxX + collider.bounds->maxX, 2));
}

CircleCollider::~CircleCollider() {
}

