/*
 * CollisionEngine.h
 *
 *  Created on: Oct 11, 2014
 *      Author: amu
 */

#ifndef COLLISIONENGINE_H_
#define COLLISIONENGINE_H_

#include "../controller/MovingEntity.h"
#include "../models/Camera.h"

class CollisionEngine {
public:
	CollisionEngine();
	virtual ~CollisionEngine();

	static bool checkForCameraBounds(MovingEntity&, Camera&);
};

#endif /* COLLISIONENGINE_H_ */
