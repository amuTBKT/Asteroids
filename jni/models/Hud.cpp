/*
 * Hud.cpp
 *
 *  Created on: Oct 23, 2014
 *      Author: amu
 */

#include "Hud.h"

Hud::Hud() {
	meter = new Meter(20);
	lStatus = new LifeStatus(10);
}

void Hud::init(){
	meter->init();
	meter->position.set(GLOBAL_VAR::SCREEN_WIDTH - 60, GLOBAL_VAR::SCREEN_HEIGHT - 30);
	lStatus->init();
	lStatus->position.set(10, GLOBAL_VAR::SCREEN_HEIGHT - 30);
}

void Hud::render(){
	if (MeteoroidManager::decLife){
		lStatus->kill();
		MeteoroidManager::decLife = false;
	}

	meter->render();
	lStatus->render();
}

Hud::~Hud() {
}

