/*
 * ExplosionManager.cpp
 *
 *  Created on: Oct 20, 2014
 *      Author: amu
 */

#include "ExplosionManager.h"

ExplosionManager::ExplosionManager() {
	for (int i = 0; i < 10; i++){
		explosions[i] = Explosion();
		explosions[i].init();
	}
}

void ExplosionManager::addExplosion(Vector2& pos){
	for (int i = 0; i < 10; i++){
		if (!explosions[i].isActive){
			explosions[i].position = pos;
			explosions[i].isActive = true;
			return;
		}
	}
}

void ExplosionManager::update(){
	for (int i = 0; i < 10; i++){
		explosions[i].render();
	}
}

ExplosionManager::~ExplosionManager() {
}

