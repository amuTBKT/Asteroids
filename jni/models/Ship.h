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
	Ship();
	virtual ~Ship();

	void update();
protected:
	void createMesh(int);
};

#endif /* SHIP_H_ */
