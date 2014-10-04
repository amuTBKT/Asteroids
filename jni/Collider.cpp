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

void Collider::setBounds(float mX, float MX, float mY, float MY){
	//	*bounds = {mX, MX, mY, MY};
	bounds->minX = mX;
	bounds->maxX = MX;
	bounds->minY = mY;
	bounds->maxY = MY;
}

Collider::~Collider() {
	delete bounds;
}

