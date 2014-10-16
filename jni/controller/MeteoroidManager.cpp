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
		m.transform.setPosition(Vector2(400, 240));
		m.transform.setVelocity(Vector2(1, 0));
		m.isActive = false;
		sMeteoroids.push_back(m);
	}
	for (int i = 0; i < capacity / 2; i++){
		Meteoroid m(20);
		m.transform.setPosition(Vector2(400, 240));
		m.transform.setVelocity(Vector2(0, 1));
		m.isActive = false;
		bMeteoroids.push_back(m);
	}
}

void MeteoroidManager::update(){
	for (int i = 0; i < capacity; i++){
		if (sMeteoroids[i].isActive){
			sMeteoroids[i].update();
			Vector2 *pos = &sMeteoroids[i].transform.position;
			if (pos->x > GLOBAL_VAR::SCREEN_WIDTH || pos->x < 0 || pos->y > GLOBAL_VAR::SCREEN_HEIGHT || pos->y < 0) sMeteoroids[i].isActive = false;
			delete pos;
		}
	}
	for (int i = 0; i < capacity / 2; i++){
		if (bMeteoroids[i].isActive){
			bMeteoroids[i].update();
			Vector2 *pos = &bMeteoroids[i].transform.position;
			if (pos->x > GLOBAL_VAR::SCREEN_WIDTH || pos->x < 0 || pos->y > GLOBAL_VAR::SCREEN_HEIGHT || pos->y < 0) bMeteoroids[i].isActive = false;
			delete pos;
		}
	}
}

void MeteoroidManager::genCirclePattern(Vector2 pos){
	float radius = GLOBAL_VAR::SCREEN_HEIGHT / 2;
	float numMeteors = 8;
	for (int i = 0; i < numMeteors; i++){
		float x = GLOBAL_VAR::SCREEN_WIDTH / 2 + radius * cosf(2 * M_PI * i / numMeteors);
		float y = GLOBAL_VAR::SCREEN_HEIGHT / 2 + radius * sinf(2 * M_PI * i / numMeteors);
		Vector2 speed = Vector2(pos.x - x, pos.y - y);
		speed.normalize();
		genNewMeteoroid(1, Vector2(x, y), speed * 2);
	}
}

void MeteoroidManager::genNewMeteoroid(int t, Vector2 pos, Vector2 vel){
	if (t){
		for (int i = 0; i < capacity / 2; i++){
			if (!bMeteoroids[i].isActive){
				bMeteoroids[i].isActive = true;
				bMeteoroids[i].transform.setPosition(pos);
				bMeteoroids[i].transform.setVelocity(vel);
				return;
			}
		}
	}
	else {
		for (int i = 0; i < capacity; i++){
			if (!sMeteoroids[i].isActive){
				sMeteoroids[i].isActive = true;
				sMeteoroids[i].transform.setPosition(pos);
				sMeteoroids[i].transform.setVelocity(vel);
				return;
			}
		}
	}
}

MeteoroidManager::~MeteoroidManager() {
}

