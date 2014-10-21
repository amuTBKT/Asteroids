/*
 * MovingEntity.cpp
 *
 *  Created on: Oct 9, 2014
 *      Author: amu
 */

#include "MovingEntity.h"

MovingEntity::MovingEntity() {
	mesh = new Mesh();
}

void MovingEntity::update(){
	GameObject::update();

	glPushMatrix();
	glTranslatef(transform.position.x, transform.position.y, 0);
	glRotatef(transform.rotation, 0, 0, 1);
	mesh->render(GL_LINE_LOOP);
	glPopMatrix();

	// render collider
	if (GLOBAL_VAR::debugPhysics){
		collider.render();
	}
}

MovingEntity::~MovingEntity() {
}

