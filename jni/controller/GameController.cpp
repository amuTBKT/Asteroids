/*
 * GameController.cpp
 *
 *  Created on: Oct 11, 2014
 *      Author: amu
 */

#include "GameController.h"

GameController::GameController(){
	GLOBAL_VAR::camera = 0;
}

void GameController::init(){
	meteoroidManager = new MeteoroidManager();
	meteoroidManager->init();
}

void GameController::setCamera(const Camera& c){
	GLOBAL_VAR::camera = new Camera(c);
}

void GameController::updateCamera(float width, float height){
	GLOBAL_VAR::SCREEN_WIDTH = width;
	GLOBAL_VAR::SCREEN_HEIGHT = height;
	glViewport(0, 0, width, height);
	if (GLOBAL_VAR::camera == 0){
		GLOBAL_VAR::camera = new Camera(width, height);
		GLOBAL_VAR::camera->transform.setPosition(Vector2(width / 2, height / 2));
		GLOBAL_VAR::camera->update();
	}
	else {
		GLOBAL_VAR::camera->width = width;
		GLOBAL_VAR::camera->height = height;
		GLOBAL_VAR::camera->transform.setPosition(Vector2(width / 2, height / 2));
		GLOBAL_VAR::camera->update();
	}
}

Camera& GameController::getCamera(){
	return *GLOBAL_VAR::camera;
}

void GameController::setShip(const Ship& s){
	ship = new Ship(s);
}

Ship& GameController::getShip(){
	return *ship;
}

void GameController::slowShip(){
	ship->transform.velocity.normalize();
	ship->transform.velocity *= shipBSpeed;
}

void GameController::accelerateShip(){
	ship->transform.velocity.normalize();
	ship->transform.velocity *= shipNSpeed;
}

void GameController::update(){
	meteoroidManager->update(*ship);
	ship->update();
	meteoroidManager->checkForCollison(ship->bulletManager.bVector);
}

GameController::~GameController() {
}

