/*
 * GLOBALVAR.h
 *
 *  Created on: Oct 14, 2014
 *      Author: amu
 */

#ifndef GLOBALVAR_H_
#define GLOBALVAR_H_

#include "../models/Camera.h"

class GLOBAL_VAR {
public:
	static int SCREEN_WIDTH, SCREEN_HEIGHT;
	static Camera* camera;
	static bool PAUSE_GAME, RESUME_GAME;
	static bool debugPhysics;
};

#endif /* GLOBALVAR_H_ */
