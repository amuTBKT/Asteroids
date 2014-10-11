/*
 * Collider.cpp
 *
 *  Created on: Oct 3, 2014
 *      Author: amu
 */

#include "Collider.h"

Collider::Collider() {
	position = Vector2(0, 0);
	setBounds(1, 1);
	checkForCollision = true;
}

Collider::Collider(const Collider& c){
	position = c.position;
	setBounds(c.bounds.width, c.bounds.height);
	checkForCollision = true;
}

void Collider::setBounds(float w, float h){
	bounds.width = w;
	bounds.height = h;
}

void Collider::translate(float dx, float dy){
	translate(Vector2(dx, dy));
}

void Collider::translate(const Vector2& dV){
	position += dV;
}

bool Collider::inBounds(const Vector2& point){
	return ((point.x >= position.x - bounds.width / 2 && point.x <= position.x + bounds.width / 2) & (point.y >= position.y - bounds.height / 2 && point.y <= position.y + bounds.height / 2));
}

bool Collider::inBounds(float x, float y){
	return inBounds(Vector2(x, y));
}

bool Collider::testAABB(const Collider& collider){
	if (position.x + bounds.width / 2 < collider.position.x - collider.bounds.width / 2) return false;
	if (position.x - bounds.width / 2 > collider.position.x + collider.bounds.width / 2) return false;
	if (position.y + bounds.height / 2  < collider.position.y - collider.bounds.height / 2) return false;
	if (position.y - bounds.height / 2 > collider.position.y + collider.bounds.height / 2) return false;

	// there is an overlap
	return true;
}

Collider::~Collider() {
}

