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

class Ship : public MovingEntity {
public:
	Ship(int);
	virtual ~Ship();

	void update();
	void shoot();
protected:
	void createMesh(int);
};

#endif /* SHIP_H_ */
