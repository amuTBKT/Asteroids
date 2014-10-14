/*
 * GameController.cpp
 *
 *  Created on: Oct 11, 2014
 *      Author: amu
 */

#include "GameController.h"

GameController::GameController(){
	camera = 0;
}

void GameController::setCamera(const Camera& c){
	camera = new Camera(c);
}

void GameController::updateCamera(float width, float height){
	SCREEN_WIDTH = width;
	SCREEN_HEIGHT = height;
	glViewport(0, 0, width, height);
	if (camera == 0){
		camera = new Camera(width, height);
		camera->transform.setPosition(Vector2(width / 2, height / 2));
		camera->update();
	}
	else {
		camera->width = width;
		camera->height = height;
		camera->transform.setPosition(Vector2(width / 2, height / 2));
		camera->update();
	}
}

Camera& GameController::getCamera(){
	return *camera;
}

void GameController::setShip(const Ship& s){
	ship = new Ship(s);
}

Ship& GameController::getShip(){
	return *ship;
}

void GameController::addBody(MovingEntity g){
	objects.push_back(g);
}

void GameController::update(){
	ship->update();
	if (CollisionEngine::checkForCameraBounds(*ship, *camera)){
		Vector2 *pos = &ship->transform.position;
		if (pos->x > SCREEN_WIDTH) pos->x -= SCREEN_WIDTH;
		if (pos->x < 0) pos->x += SCREEN_WIDTH;
		if (pos->y > SCREEN_HEIGHT) pos->y -= SCREEN_HEIGHT;
		if (pos->y < 0) pos->y += SCREEN_HEIGHT;
	}

	for (int i = 0; i < objects.size(); i++){
		objects[i].update();
		CollisionEngine::checkForCameraBounds(objects[i], *camera);
	}
}

GameController::~GameController() {
}

