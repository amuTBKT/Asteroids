/*
 * MovingEntity.cpp
 *
 *  Created on: Oct 9, 2014
 *      Author: amu
 */

#include "MovingEntity.h"

MovingEntity::MovingEntity() {
}

void MovingEntity::move(){
	velocity += acceletaion;
	transform.position += velocity;
}

MovingEntity::~MovingEntity() {
}

