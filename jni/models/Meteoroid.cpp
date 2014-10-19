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
		float x = radius * cosf(2 * M_PI * i / resolution) + Random::genRandomNumber(radius / 4, radius / 2);
		float y = radius * sinf(2 * M_PI * i / resolution) + Random::genRandomNumber(radius / 4, radius / 2);

		// for rendering using GL_LINES
		// not required for now
//		if (i > 0){
//			int tmp = counter;
//			data[counter++] = data[tmp - 2];
//			data[counter++] = data[tmp - 1];
//			data[counter++] = data[tmp - 0];
//		}
//		if (i == 5){
//			data[counter++] = data[0 + 0];
//			data[counter++] = data[0 + 1];
//			data[counter++] = data[0 + 2];
//		}

		data[counter++] = x;
		data[counter++] = y;
		data[counter++] = 0;
	}
	mesh->setVertices(&data[0], sizeof(data) / sizeof(float), false);
}
