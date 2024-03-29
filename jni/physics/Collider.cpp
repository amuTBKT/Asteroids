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

bool Collider::testSphere(const Collider& collider){
	float thresholdDis = bounds.width / 2 + collider.bounds.width / 2;
	Vector2 v = position - collider.position;
	if (v.getLengthSQR() > thresholdDis * thresholdDis) return false;

	// there is an overlap
	return true;
}

void Collider::render(){
	GLfloat data[] =	{
							position.x - bounds.width / 2, position.y - bounds.height / 2, 0, 1, 0, 0, 1,
							position.x - bounds.width / 2, position.y + bounds.height / 2, 0, 1, 0, 0, 1,
							position.x + bounds.width / 2, position.y + bounds.height / 2, 0, 1, 0, 0, 1,
							position.x + bounds.width / 2, position.y - bounds.height / 2, 0, 1, 0, 0, 1
					 	 };
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 7 * sizeof(float), &data[0]);
	glEnableClientState(GL_COLOR_ARRAY);
	glColorPointer(4, GL_FLOAT, 7 * sizeof(float), &data[3]);
	glDrawArrays(GL_LINE_LOOP, 0, 4);
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);
}

void Collider::renderAsSphere(){
	int resolution = 8;
	GLfloat data[resolution * 7];
	int counter = 0;
	for (int i = 0; i < resolution; i++){
		float x = position.x + (bounds.width / 2) * cosf(2 * M_PI * i / resolution);
		float y = position.y + (bounds.width / 2) * sinf(2 * M_PI * i / resolution);
		data[counter++] = x;	// x
		data[counter++] = y;	// y
		data[counter++] = 0;	// z
		data[counter++] = 0;	// r
		data[counter++] = 1;	// g
		data[counter++] = 0;	// b
		data[counter++] = 1;	// a
	}
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 7 * sizeof(GLfloat), &data[0]);
	glEnableClientState(GL_COLOR_ARRAY);
	glColorPointer(4, GL_FLOAT, 7 * sizeof(GLfloat), &data[3]);
	glDrawArrays(GL_LINE_LOOP, 0, sizeof(data) / (sizeof(GLfloat) * 7));
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);
}

Collider::~Collider() {
}

