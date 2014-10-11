/*
 * CollisionEngine.h
 *
 *  Created on: Oct 11, 2014
 *      Author: amu
 */

#ifndef COLLISIONENGINE_H_
#define COLLISIONENGINE_H_

#include "../controller/GameObject.h"
#include "../controller/GameController.h"

class CollisionEngine {
public:
	CollisionEngine();
	virtual ~CollisionEngine();

	static void update();
};

#endif /* COLLISIONENGINE_H_ */
