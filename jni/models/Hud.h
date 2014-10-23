/*
 * Hud.h
 *
 *  Created on: Oct 23, 2014
 *      Author: amu
 */

#ifndef HUD_H_
#define HUD_H_

#include "Meter.h"
#include "../core/GLOBALVAR.h"

class Hud {
public:
	Meter *meter;

	Hud();
	virtual ~Hud();

	void init();
	void render();
};

#endif /* HUD_H_ */
