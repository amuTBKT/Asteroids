/*
 * BulletManager.h
 *
 *  Created on: Oct 11, 2014
 *      Author: amu
 */

#ifndef BULLETMANAGER_H_
#define BULLETMANAGER_H_

#include "../models/Bullet.h"
#include "../models/Camera.h"
#include "../physics/CollisionEngine.h"
#include <vector>

class BulletManager {
public:
	// bullet parameters
	float radius, speed;
	std::vector<Bullet> bVector;

	BulletManager();
	virtual ~BulletManager();

	void shoot(const Vector2&, float);
	void update(Camera&);
};

#endif /* BULLETMANAGER_H_ */
