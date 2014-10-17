/*
 * Ship.h
 *
 *  Created on: Oct 10, 2014
 *      Author: amu
 */

#ifndef SHIP_H_
#define SHIP_H_

#include "../controller/MovingEntity.h"
#include "../controller/BulletManager.h"
#include "../core/FileLoader.h"

class Ship : public MovingEntity {
public:
	BulletManager bulletManager;

	Ship(int);
	virtual ~Ship();

	void update();
	void shoot();

protected:
	void createMesh(int);
};

#endif /* SHIP_H_ */
