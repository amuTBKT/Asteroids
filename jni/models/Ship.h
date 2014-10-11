/*
 * Ship.h
 *
 *  Created on: Oct 10, 2014
 *      Author: amu
 */

#include "../controller/MovingEntity.h"

#ifndef SHIP_H_
#define SHIP_H_

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
