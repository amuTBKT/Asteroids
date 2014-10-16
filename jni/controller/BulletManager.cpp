/*
 * BulletManager.cpp
 *
 *  Created on: Oct 11, 2014
 *      Author: amu
 */

#include "BulletManager.h"

BulletManager::BulletManager() {
	radius = 2;
	speed = 20;
	capacity = 20;
	for (int i = 0; i < capacity; i++){
		Bullet b(radius);
		b.isActive = false;
		bVector.push_back(b);
	}
}

void BulletManager::update(){
	for (int i = 0; i < capacity; i++){
		if (bVector[i].isActive){
			bVector[i].update();
			Vector2 *pos = &bVector[i].transform.position;
			if (pos->x > GLOBAL_VAR::SCREEN_WIDTH || pos->x < 0 || pos->y > GLOBAL_VAR::SCREEN_HEIGHT || pos->y < 0) bVector[i].isActive = false;
			delete pos;
		}
	}
}

void BulletManager::shoot(const Vector2& pos, float angle){
	angle *= M_PI / 180;
	for (int i = 0; i < capacity; i++){
		if (!bVector[i].isActive){
			bVector[i].isActive = true;
			bVector[i].transform.setPosition(pos);
			bVector[i].transform.setVelocity(Vector2(cosf(angle), sinf(angle)) * speed);
			return;
		}
	}
}

BulletManager::~BulletManager() {
}

