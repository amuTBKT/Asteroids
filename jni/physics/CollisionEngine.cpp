/*
 * CollisionEngine.cpp
 *
 *  Created on: Oct 11, 2014
 *      Author: amu
 */

#include "CollisionEngine.h"

CollisionEngine::CollisionEngine() {

}

bool CollisionEngine::checkForCameraBounds(MovingEntity& me, Camera& camera){
	me.collider.cWCameraBound.h = 0;
	me.collider.cWCameraBound.v = 0;

	MovingEntity *tmp = &me;
	if (tmp->collider.testAABB(camera.getTopBound())){
//		tmp->transform.velocity.y *= -1; // tmp
		me.collider.cWCameraBound.v = -1;
		return true;
	}

	if (tmp->collider.testAABB(camera.getBottomBound())){
		me.collider.cWCameraBound.v = 1;
		return true;
	}

	if (tmp->collider.testAABB(camera.getLeftBound())){
//		tmp->transform.velocity.x *= -1; // tmp
		me.collider.cWCameraBound.h = 1;
		return true;
	}

	if (tmp->collider.testAABB(camera.getRightBound())){
		me.collider.cWCameraBound.h = -1;
		return true;
	}

	return false;
}

CollisionEngine::~CollisionEngine() {
}

