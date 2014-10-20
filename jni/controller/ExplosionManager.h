/*
 * ExplosionManager.h
 *
 *  Created on: Oct 20, 2014
 *      Author: amu
 */

#ifndef EXPLOSIONMANAGER_H_
#define EXPLOSIONMANAGER_H_

#include "../particles/Explosion.h"

class ExplosionManager {
public:
	Explosion explosions[10];

	ExplosionManager();
	virtual ~ExplosionManager();

	void addExplosion(Vector2&);
	void update();
};

#endif /* EXPLOSIONMANAGER_H_ */
