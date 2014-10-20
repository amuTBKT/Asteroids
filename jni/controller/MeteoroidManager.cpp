/*
 * MeteoroidManager.cpp
 *
 *  Created on: Oct 16, 2014
 *      Author: amu
 */

#include "MeteoroidManager.h"

MeteoroidManager::MeteoroidManager() {
	capacity = 20;
	speed = 1.5;
	sActiveMeteors = 0;
	bActiveMeteors = 0;
	proxyShip = new pShip();
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
	expManager = new ExplosionManager();
}

void MeteoroidManager::update(Ship& ship){
	proxyShip->pos = ship.transform.position;
	proxyShip->vel = ship.transform.velocity;

	//// spawning new meteoroids ////
	if (bActiveMeteors < 3) spawnMeteoroid(1);
	if (sActiveMeteors < 4) spawnMeteoroid(0);
	/////////////////////////////////

	//// destroying meteoroid if it goes off the screen ////
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
	////////////////////////////////////////////////////////

	expManager->update();
}

bool MeteoroidManager::checkForCollison(std::vector<Bullet> &bVector){
	for (int i = 0; i < capacity / 2; i++){
		if (bMeteoroids[i].isActive){
			for (int j = 0; j < bVector.size(); j++){
				if (bVector[j].isActive){
					if (bMeteoroids[i].collider.testAABB(bVector[j].collider)){
						bMeteoroids[i].isActive = false;
						bActiveMeteors--;
						bVector[j].isActive = false;

						expManager->addExplosion(bVector[j].transform.position);

						Vector2 *vel = &bMeteoroids[i].transform.velocity;
						vel->rotate(20 * Random::genRandomFloat()); vel->normalize(); *vel *= speed * 1.5;
						genNewMeteoroid(0, bMeteoroids[i].transform.position + *vel, *vel); 	//TODO: random velocity
						*vel = bMeteoroids[i].transform.velocity;
						vel->rotate(-20 * Random::genRandomFloat()); vel->normalize(); *vel *= speed * 1.5;
						genNewMeteoroid(0, bMeteoroids[i].transform.position + *vel, *vel); 	//TODO: random velocity
						delete vel;
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

						expManager->addExplosion(bVector[j].transform.position);
					}
				}
			}
		}
	}

	return false;
}

void MeteoroidManager::genCirclePattern(Vector2 pos){
	float radius = GLOBAL_VAR::SCREEN_HEIGHT / 2;
	float numMeteors = 5;
	for (int i = 0; i < numMeteors; i++){
		float x = GLOBAL_VAR::SCREEN_WIDTH / 2 + radius * cosf(2 * M_PI * i / numMeteors);
		float y = GLOBAL_VAR::SCREEN_HEIGHT / 2 + radius * sinf(2 * M_PI * i / numMeteors);
		Vector2 speed = Vector2(pos.x - x, pos.y - y);
		speed.rotate(Random::genRandomFloat() * 10);
		speed.normalize();
		genNewMeteoroid(1, Vector2(x, y), speed * 2);
	}
}

void MeteoroidManager::spawnMeteoroid(int t){
	float r = Random::genRandomFloat();

	if (r < 0.5){
		r = Random::genRandomFloat();
		if (r < 0.5){
			float x = Random::genRandomNumber(-20, 2);
			float y = Random::genRandomNumber(20, GLOBAL_VAR::SCREEN_HEIGHT - 20);
			Vector2 vel = proxyShip->pos - Vector2(x, y);	vel.normalize();	vel *= speed;
			genNewMeteoroid(t, Vector2(x, y), vel);
		}
		else {
			float x = Random::genRandomNumber(20, GLOBAL_VAR::SCREEN_WIDTH - 20);
			float y = Random::genRandomNumber(GLOBAL_VAR::SCREEN_HEIGHT + 10, GLOBAL_VAR::SCREEN_HEIGHT + 20);
			Vector2 vel = proxyShip->pos - Vector2(x, y);	vel.normalize();	vel *= speed;
			genNewMeteoroid(t, Vector2(x, y), vel);
		}
	}
	else {
		r = Random::genRandomFloat();
		if (r < 0.5){
			float x = Random::genRandomNumber(GLOBAL_VAR::SCREEN_WIDTH + 10, GLOBAL_VAR::SCREEN_WIDTH + 20);
			float y = Random::genRandomNumber(20, GLOBAL_VAR::SCREEN_HEIGHT - 20);
			Vector2 vel = proxyShip->pos - Vector2(x, y);	vel.normalize();	vel *= speed;
			genNewMeteoroid(t, Vector2(x, y), vel);
		}
		else {
			float x = Random::genRandomNumber(20, GLOBAL_VAR::SCREEN_WIDTH - 20);
			float y = Random::genRandomNumber(-20, 2);
			Vector2 vel = proxyShip->pos - Vector2(x, y);	vel.normalize();	vel *= speed;
			genNewMeteoroid(t, Vector2(x, y), vel);
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

