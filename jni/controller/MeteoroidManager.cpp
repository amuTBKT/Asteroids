/*
 * MeteoroidManager.cpp
 *
 *  Created on: Oct 16, 2014
 *      Author: amu
 */

#include "MeteoroidManager.h"

MeteoroidManager::MeteoroidManager() {
	capacity = 20;
}

void MeteoroidManager::init(){
	for (int i = 0; i < capacity; i++){
		Meteoroid m(10);
		meteoroids.push_back(m);
	}
}

void MeteoroidManager::update(){
	for (int i = 0; i < capacity; i++){
		if (meteoroids[i].isActive){
			meteoroids[i].update();
			Vector2 *pos = &meteoroids[i].transform.position;
			if (pos->x > GLOBAL_VAR::SCREEN_WIDTH || pos->x < 0 || pos->y > GLOBAL_VAR::SCREEN_HEIGHT || pos->y < 0) meteoroids[i].isActive = false;
			delete pos;
		}
	}
}

void MeteoroidManager::genNewMeteoroid(){
	for (int i = 0; i < capacity; i++){
		if (!meteoroids[i].isActive){
			meteoroids[i].isActive = true;
			meteoroids[i].transform.setPosition(Vector2(400, 240));
			meteoroids[i].transform.setVelocity(Vector2(5, 0));
			return;
		}
	}
}

MeteoroidManager::~MeteoroidManager() {
}

