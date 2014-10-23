/*
 * Meter.cpp
 *
 *  Created on: Oct 23, 2014
 *      Author: amu
 */

#include "Meter.h"

Meter::Meter() {
	bar = 0;
	border = 0;
}

void Meter::render(){
	glPushMatrix();
	glTranslatef(position.x, position.y, 0);
	border->render(GL_LINE_LOOP);
	glTranslatef(50, 0, 0);
	glScalef(0.5, 1, 0);
	bar->render(GL_TRIANGLES);
	glPopMatrix();
}

void Meter::init(){
	crateMesh(20);
}

Meter::~Meter() {
}

