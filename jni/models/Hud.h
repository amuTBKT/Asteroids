/*
 * Hud.h
 *
 *  Created on: Oct 23, 2014
 *      Author: amu
 */

#ifndef HUD_H_
#define HUD_H_

#include "Meter.h"
#include "LifeStatus.h"
#include "../core/GLOBALVAR.h"
#include "../controller/MeteoroidManager.h"

class Hud {
public:
	Meter *meter;
	LifeStatus *lStatus;

	Hud();
	virtual ~Hud();

	void init();
	void render();
};

#endif /* HUD_H_ */
