/*
 * Hud.cpp
 *
 *  Created on: Oct 23, 2014
 *      Author: amu
 */

#include "Hud.h"

Hud::Hud() {
	meter = new Meter(20);
}

void Hud::init(){
	meter->init();
	meter->position.set(854 - 60, 480 - 30);
}

void Hud::render(){
	meter->render();
}

Hud::~Hud() {
}

