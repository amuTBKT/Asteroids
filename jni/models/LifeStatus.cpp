/*
 * LifeStatus.cpp
 *
 *  Created on: Oct 24, 2014
 *      Author: amu
 */

#include "LifeStatus.h"

LifeStatus::LifeStatus(float scl) {
	maxLife = 4;
	minLife = 0;
	mesh = 0;
	life = maxLife;
	scale = scl;
}

void LifeStatus::init(){
	createMesh(scale);
}

void LifeStatus::kill(){
	life -= 1;
	if (life <= 0) life = 0;
}

void LifeStatus::render(){
	glPushMatrix();
	glTranslatef(position.x, position.y, 0);
	for (int i = 0; i < life; i++){
		glTranslatef(scale * 2 + scale, 0, 0);
		mesh->render(GL_LINE_LOOP);
	}
	glPopMatrix();
}

LifeStatus::~LifeStatus() {
}

