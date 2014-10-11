/*
 * Bullet.cpp
 *
 *  Created on: Oct 10, 2014
 *      Author: amu
 */

#include "Bullet.h"

Bullet::Bullet(float r) {
	radius = r;
	createMesh(5);
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

