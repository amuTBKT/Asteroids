/*
 * Ship.cpp
 *
 *  Created on: Oct 10, 2014
 *      Author: amu
 */

#include "Ship.h"

Ship::Ship() {
	createMesh();
	collider.setBounds(40, 40);
}

void Ship::update(){
	GameObject::update();

	transform.rotation = 180 * atan2f(transform.velocity.y, transform.velocity.x) / M_PI;

	glPushMatrix();
	glTranslatef(transform.position.x, transform.position.y, 0);
	glRotatef(transform.rotation, 0, 0, 1);
	mesh->render();
	glPopMatrix();
}

void Ship::createMesh(){
	float data[4 * 3];
	float scaleX = 20, scaleY = 20;
	data[0] =  scaleX;			data[1]  = 0;			data[2]  = 0;
	data[3] = -scaleX;			data[4]  = scaleY;		data[5]  = 0;
	data[6] = -scaleX / 2;		data[7]  = 0;			data[8]  = 0;
	data[9] = -scaleX;			data[10] = -scaleY;		data[11] = 0;
	mesh = new Mesh();
	mesh->setVertices(&data[0], sizeof(data) / sizeof(float), false);
}

Ship::~Ship() {
}

