/*
 * MeteoroidManager.cpp
 *
 *  Created on: Oct 16, 2014
 *      Author: amu
 */

#include "MeteoroidManager.h"

MeteoroidManager::MeteoroidManager() {
	capacity = 20;
	sActiveMeteors = 0;
	bActiveMeteors = 0;
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
	if (bActiveMeteors < 5) spawnMeteoroid(1);

	for (int i = 0; i < capacity; i++){
		if (sMeteoroids[i].isActive){
			sMeteoroids[i].update();
			Vector2 *pos = &sMeteoroids[i].transform.position;
			Vector2 *vel = &sMeteoroids[i].transform.velocity;
			if (checkForBounds(pos, vel)) {
				sMeteoroids[i].isActive = false;
				sActiveMeteors--;
			}
			delete pos;
			delete vel;
		}
	}
	for (int i = 0; i < capacity / 2; i++){
		if (bMeteoroids[i].isActive){
			bMeteoroids[i].update();
			Vector2 *pos = &bMeteoroids[i].transform.position;
			Vector2 *vel = &bMeteoroids[i].transform.velocity;
			if (checkForBounds(pos, vel)) {
				bMeteoroids[i].isActive = false;
				bActiveMeteors--;
			}
			delete pos;
			delete vel;
		}
	}
}

bool MeteoroidManager::checkForCollison(std::vector<Bullet> &bVector){
	for (int i = 0; i < capacity / 2; i++){
		if (bMeteoroids[i].isActive){
			for (int j = 0; j < bVector.size(); j++){
				if (bVector[j].isActive){
					if (bMeteoroids[i].collider.testAABB(bVector[j].collider)){
						bMeteoroids[i].isActive = false;
						bActiveMeteors--;
						genNewMeteoroid(0, bMeteoroids[i].transform.position, Random::genRandomVector2(2)); 	//TODO: random velocity
						genNewMeteoroid(0, bMeteoroids[i].transform.position, Random::genRandomVector2(2)); 	//TODO: random velocity
						sActiveMeteors += 2;
						bVector[j].isActive = false;
					}
				}
			}
		}
	}

	for (int i = 0; i < capacity; i++){
		if (sMeteoroids[i].isActive){
			for (int j = 0; j < bVector.size(); j++){
				if (bVector[j].isActive){
					if (sMeteoroids[i].collider.testAABB(bVector[j].collider)){
						sMeteoroids[i].isActive = false;
						sActiveMeteors--;
						bVector[j].isActive = false;
					}
				}
			}
		}
	}

	return false;
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

void MeteoroidManager::spawnMeteoroid(int t){
	float r = Random::genRandomFloat();

	if (r < 0.5){
		r = Random::genRandomFloat();
		if (r < 0.5){
			genNewMeteoroid(t, Vector2(Random::genRandomNumber(-20, 2), Random::genRandomNumber(20, GLOBAL_VAR::SCREEN_HEIGHT - 20)), Vector2(3, 0));
		}
		else {
			genNewMeteoroid(t, Vector2(Random::genRandomNumber(20, GLOBAL_VAR::SCREEN_WIDTH - 20), Random::genRandomNumber(GLOBAL_VAR::SCREEN_HEIGHT + 10, GLOBAL_VAR::SCREEN_HEIGHT + 20)), Vector2(0, -3));
		}
	}
	else {
		r = Random::genRandomFloat();
		if (r < 0.5){
			genNewMeteoroid(t, Vector2(Random::genRandomNumber(GLOBAL_VAR::SCREEN_WIDTH + 10, GLOBAL_VAR::SCREEN_WIDTH + 20), Random::genRandomNumber(20, GLOBAL_VAR::SCREEN_HEIGHT - 20)), Vector2(-3, 0));
		}
		else {
			genNewMeteoroid(t, Vector2(Random::genRandomNumber(20, GLOBAL_VAR::SCREEN_WIDTH - 20), Random::genRandomNumber(-20, 2)), Vector2(0, 3));
		}
	}
}

void MeteoroidManager::genNewMeteoroid(int t, Vector2 pos, Vector2 vel){
	if (t){
		for (int i = 0; i < capacity / 2; i++){
			if (!bMeteoroids[i].isActive){
				bMeteoroids[i].isActive = true;
				bMeteoroids[i].transform.setPosition(pos);
				bMeteoroids[i].transform.setVelocity(vel);
				bActiveMeteors++;
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
				sActiveMeteors++;
				return;
			}
		}
	}
}

MeteoroidManager::~MeteoroidManager() {
}

