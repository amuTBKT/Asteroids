/*
 * GameController.h
 *
 *  Created on: Oct 11, 2014
 *      Author: amu
 */

#ifndef GAMECONTROLLER_H_
#define GAMECONTROLLER_H_

#include <vector>
#include "../models/Ship.h"
#include "MeteoroidManager.h"

class GameController {
public:
	static Ship* ship;
	static MeteoroidManager *meteoroidManager;

	GameController();
	virtual ~GameController();

	static void init();
	static void setCamera(const Camera&);
	static Camera& getCamera();
	static void setShip(const Ship&);
	static Ship& getShip();
	static void slowShip(float);
	static void accelerateShip(float);
	static void updateCamera(float, float);
	static void update();
};

#endif /* GAMECONTROLLER_H_ */
