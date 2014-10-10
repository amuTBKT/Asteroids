/*
 * Meteoroid.cpp
 *
 *  Created on: Oct 9, 2014
 *      Author: amu
 */

#include <math.h>
#include "Meteoroid.h"

Meteoroid::Meteoroid(float r) {
	radius = r;
	createMesh(8);
	collider.setBounds(2 * r, 2 * r);
}

Meteoroid::~Meteoroid() {
}

void Meteoroid::update(){
	GameObject::update();

	glPushMatrix();
	glRotatef(transform.rotation, 0, 0, 1);
	glTranslatef(transform.position.x, transform.position.y, 0);
	mesh->render();
	glPopMatrix();
}

void Meteoroid::createMesh(int resolution) {
	float data[resolution * 3];
	int counter = 0;
	for (int i = 0; i < resolution; i++){
		float x = radius * cosf(2 * M_PI * i / resolution);
		float y = radius * sinf(2 * M_PI * i / resolution);

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
	mesh = new Mesh();
	mesh->setVertices(&data[0], sizeof(data) / sizeof(float), false);
}
