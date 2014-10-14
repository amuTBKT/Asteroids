/*
 * BulletManager.cpp
 *
 *  Created on: Oct 11, 2014
 *      Author: amu
 */

#include "BulletManager.h"

BulletManager::BulletManager() {
	radius = 2;
	speed = 4;
	for (int i = 0; i < 60; i++){
		Bullet b(radius);
		bVector.push_back(b);
	}
}

void BulletManager::update(Camera& camera){
	for (int i = 0; i < bVector.size(); i++){
		if (bVector[i].isActive){
			bVector[i].update();

			if (CollisionEngine::checkForCameraBounds(bVector[i], camera)){
				bVector[i].isActive = false;
			}
		}
	}
}

void BulletManager::shoot(const Vector2& pos, float angle){
	angle *= M_PI / 180;
	Bullet *tmp;
	for (int i = 0; i < bVector.size(); i++){
		if (!bVector[i].isActive){
			tmp = &bVector[i];
		}
	}
	tmp->isActive = true;
	tmp->transform.setPosition(pos);
	tmp->transform.setVelocity(Vector2(cosf(angle), sinf(angle)) * speed);
}

BulletManager::~BulletManager() {
}

