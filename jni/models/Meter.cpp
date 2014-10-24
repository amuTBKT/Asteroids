/*
 * Meter.cpp
 *
 *  Created on: Oct 23, 2014
 *      Author: amu
 */

#include "Meter.h"

Meter::Meter(float scale) {
	scaleX = 2.5 * scale;
	scaleY = scale / 2;
	value = 0;
	usingMeter = false;
	bar = 0;
	border = 0;
}

void Meter::render(){
	if (!usingMeter) value += 0.1;
	else if (usingMeter) value -= 0.1;

	//// clamp value between [0, 100] ////
	if (value >= 100) value = 100;
	if (value <= 0) value = 0;
	//////////////////////////////////////

	glPushMatrix();
	glTranslatef(position.x, position.y, 0);
	border->render(GL_LINE_LOOP);
	glTranslatef(scaleX, 0, 0);
	glScalef(value / 100, 1, 0);
	bar->render(GL_TRIANGLES);
	glPopMatrix();
}

bool Meter::isEmpty(){
	return (int) value == 0;
}

void Meter::useMeter(){
	usingMeter = true;
}

void Meter::fillMeter(){
	usingMeter = false;
}

void Meter::init(){
	crateMesh(scaleY * 2);
}

Meter::~Meter() {
}

