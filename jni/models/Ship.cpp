/*
 * Ship.cpp
 *
 *  Created on: Oct 10, 2014
 *      Author: amu
 */

#include "Ship.h"

Ship::Ship() {
	createMesh(10);
	collider.setBounds(20, 20);
}

void Ship::update(){
	transform.setRotation(180 * atan2f(transform.velocity.y, transform.velocity.x) / M_PI);
	MovingEntity::update();
}

void Ship::createMesh(int scale){
	float data[4 * 3];
	float scaleX = scale, scaleY = scale;
	data[0] =  scaleX;			data[1]  = 0;			data[2]  = 0;
	data[3] = -scaleX;			data[4]  = scaleY;		data[5]  = 0;
	data[6] = -scaleX / 2;		data[7]  = 0;			data[8]  = 0;
	data[9] = -scaleX;			data[10] = -scaleY;		data[11] = 0;
	mesh->setVertices(&data[0], sizeof(data) / sizeof(float), false);
}

Ship::~Ship() {
}

