/*
 * Collider.cpp
 *
 *  Created on: Oct 3, 2014
 *      Author: amu
 */

#include "Collider.h"

Collider::Collider() {
	bounds = new aabb;
	setBounds(0, 1, 0, 1);
}

void Collider::setBounds(float mX, float MX, float mY, float MY){
	//	*bounds = {mX, MX, mY, MY};
	bounds->minX = mX;
	bounds->maxX = MX;
	bounds->minY = mY;
	bounds->maxY = MY;
}

bool Collider::inBounds(Vector2 point){
	return ((point.x >= bounds->minX && point.x <= bounds->maxX) & (point.y >= bounds->minY && point.y <= bounds->maxY));
}

bool Collider::inBounds(float x, float y){
	return inBounds(Vector2(x, y));
}

Collider::~Collider() {
	delete bounds;
}

