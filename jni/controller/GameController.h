/*
 * GameController.h
 *
 *  Created on: Oct 11, 2014
 *      Author: amu
 */

#ifndef GAMECONTROLLER_H_
#define GAMECONTROLLER_H_

#include <vector>
#include "../models/Camera.h"
#include "physics/CollisionEngine.h"
#include "../models/Ship.h"

class GameController {
public:
	static float SCREEN_WIDTH, SCREEN_HEIGHT;
	static Camera* camera;
	static Ship* ship;
	static std::vector<MovingEntity> objects;

	GameController();
	virtual ~GameController();

	static void setCamera(const Camera&);
	static Camera& getCamera();
	static void setShip(const Ship&);
	static Ship& getShip();
	static void updateCamera(float, float);
	static void addBody(MovingEntity);
	static void update();
};

#endif /* GAMECONTROLLER_H_ */
