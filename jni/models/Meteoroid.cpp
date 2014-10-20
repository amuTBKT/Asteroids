/*
 * Meteoroid.cpp
 *
 *  Created on: Oct 9, 2014
 *      Author: amu
 */

#include "Meteoroid.h"

Meteoroid::Meteoroid(float r) {
	radius = r;
	createMesh(16);
	collider.setBounds(2 * r + r / 2, 2 * r + r / 2);
}

Meteoroid::~Meteoroid() {
}

void Meteoroid::update(){
	MovingEntity::update();
}

void Meteoroid::createMesh(int resolution) {
	float data[resolution * 3];
	int counter = 0;
	for (int i = 0; i < resolution; i++){
		float x = radius * cosf(2 * M_PI * i / resolution) + (radius / 4) * (1 - 2 * Random::genRandomFloat());
		float y = radius * sinf(2 * M_PI * i / resolution) + (radius / 4) * (1 - 2 * Random::genRandomFloat());

		data[counter++] = x;
		data[counter++] = y;
		data[counter++] = 0;
	}
	mesh->setVertices(&data[0], sizeof(data) / sizeof(float), false);
}
