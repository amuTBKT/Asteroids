/*
 * Bullet.cpp
 *
 *  Created on: Oct 10, 2014
 *      Author: amu
 */

#include "Bullet.h"

Bullet::Bullet(float r) {
	radius = r;
	createMesh(8);
	collider.setBounds(2 * r, 2 * r);
	transform.setVelocity(Vector2(0, 0));
}

Bullet::Bullet(float r, const Vector2& v){
	radius = r;
	createMesh(8);
	collider.setBounds(2 * r, 2 * r);
	transform.setVelocity(v);
}

void Bullet::reset(){
	transform.setVelocity(Vector2(0, 0));
}

void Bullet::upate(){
	MovingEntity::update();
}

void Bullet::createMesh(int resolution) {
	float data[resolution * 3];
	int counter = 0;
	for (int i = 0; i < resolution; i++){
		float x = radius * cosf(2 * M_PI * i / resolution);
		float y = radius * sinf(2 * M_PI * i / resolution);

		data[counter++] = x;
		data[counter++] = y;
		data[counter++] = 0;
	}
	mesh->setVertices(&data[0], sizeof(data) / sizeof(float), false);
}

Bullet::~Bullet() {
}

