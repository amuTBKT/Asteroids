/*
 * Collider.cpp
 *
 *  Created on: Oct 3, 2014
 *      Author: amu
 */

#include "Collider.h"

Collider::Collider(const Collider& c){
	bounds = c.bounds;
}

Collider::Collider() {
	bounds = new aabb;
	setBounds(0, 1, 0, 1);
}

//void Collider::setParent(const GameObject& g){
//	gParent = g;
//}

void Collider::setBounds(float mX, float MX, float mY, float MY){
	//	*bounds = {mX, MX, mY, MY};
	bounds->minX = mX;
	bounds->maxX = MX;
	bounds->minY = mY;
	bounds->maxY = MY;
}

void Collider::translate(float dx, float dy){
	translate(Vector2(dx, dy));
}

void Collider::translate(const Vector2& dV){
	bounds->maxX += dV.x;
	bounds->minX += dV.x;
	bounds->maxY += dV.y;
	bounds->minY += dV.y;
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

Collider::~Collider() {
	delete bounds;
}

