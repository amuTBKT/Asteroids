/*
 * Ship.cpp
 *
 *  Created on: Oct 10, 2014
 *      Author: amu
 */

#include "Ship.h"

Ship::Ship(int scale) {
	createMesh(scale);
	collider.setBounds(2 * scale, 2 * scale);
	bulletManager = BulletManager();
}

void Ship::update(){
	transform.setRotation(180 * atan2f(transform.velocity.y, transform.velocity.x) / M_PI);
	MovingEntity::update();

	Vector2 *pos = &transform.position;
	if (pos->x > GLOBAL_VAR::SCREEN_WIDTH) pos->x -= GLOBAL_VAR::SCREEN_WIDTH;
	if (pos->x < 0) pos->x += GLOBAL_VAR::SCREEN_WIDTH;
	if (pos->y > GLOBAL_VAR::SCREEN_HEIGHT) pos->y -= GLOBAL_VAR::SCREEN_HEIGHT;
	if (pos->y < 0) pos->y += GLOBAL_VAR::SCREEN_HEIGHT;
	delete pos;

	bulletManager.update();
}

void Ship::shoot(){
	bulletManager.shoot(transform.position, transform.rotation);
}

void Ship::createMesh(int scale){
	float data[4 * 3];
	float scaleX = scale, scaleY = scale;
	data[0] =  scaleX;			data[1]  = 0;			data[2]  = 0;
	data[3] = -scaleX;			data[4]  = scaleY;		data[5]  = 0;
	data[6] = -scaleX / 2;		data[7]  = 0;			data[8]  = 0;
	data[9] = -scaleX;			data[10] = -scaleY;		data[11] = 0;

//	char file[] = "../res/ship.txt";
//	std::string dataString = FileLoader::loadFile(file);
//	if (dataString == "") glClearColor(1, 0, 0, 1);

	mesh->setVertices(&data[0], sizeof(data) / sizeof(float), false);
}

Ship::~Ship() {
}

