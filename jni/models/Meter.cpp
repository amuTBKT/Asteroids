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
	if (!usingMeter) value += 0.01 + value / 1000;
	else if (usingMeter) value -= 0.3;

	update();

	glPushMatrix();
	glTranslatef(position.x, position.y, 0);
	border->render(GL_LINE_LOOP);
	glTranslatef(scaleX, 0, 0);
	glScalef(value / 100, 1, 0);
	bar->render(GL_TRIANGLES);
	glPopMatrix();
}

void Meter::update(){
	//// clamp value between [0, 100] ////
	if (value >= 100) value = 100;
	if (value <= 0) value = 0;
	//////////////////////////////////////
}

bool Meter::isEmpty(){
	return (int) value == 0;
}

void Meter::startUsingMeter(){
	usingMeter = true;
}

void Meter::useMeter(float m){
	value -= m;
	update();
}

void Meter::fillMeter(){
	usingMeter = false;
}

void Meter::init(){
	crateMesh(scaleY * 2);
}

Meter::~Meter() {
}

