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

void GameController::addBody(MovingEntity g){
	objects.push_back(g);
}

void GameController::update(){
	for (int i = 0; i < objects.size(); i++){
		objects[i].update();
	}

	CollisionEngine::update();
}

GameController::~GameController() {
}

