/*
 * CollisionEngine.cpp
 *
 *  Created on: Oct 11, 2014
 *      Author: amu
 */

#include "CollisionEngine.h"

CollisionEngine::CollisionEngine() {

}

void CollisionEngine::update(){
	for (int i = 0; i < GameController::objects.size(); i++){
		MovingEntity *tmp = &GameController::objects[i];
		if (tmp->collider.testAABB(GameController::camera->getTopBound()) || tmp->collider.testAABB(GameController::camera->getBottomBound())){
			tmp->transform.velocity.y *= -1;
		}
		if (tmp->collider.testAABB(GameController::camera->getLeftBound()) || tmp->collider.testAABB(GameController::camera->getRightBound())){
			tmp->transform.velocity.x *= -1;
		}
	}
}

CollisionEngine::~CollisionEngine() {
}

