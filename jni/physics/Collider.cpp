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

Collider::~Collider() {
	delete bounds;
}

