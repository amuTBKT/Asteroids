/*
 * Meteoroid.h
 *
 *  Created on: Oct 9, 2014
 *      Author: amu
 */

#ifndef METEOROID_H_
#define METEOROID_H_

#include <math.h>
#include "../controller/MovingEntity.h"
#include "../core/Random.h"

class Meteoroid : public MovingEntity{
public:
	// graphics
	float radius;
	bool isActive;

	Meteoroid(float);
	virtual ~Meteoroid();
	void update();

protected:
	void createMesh(int);
};

#endif /* METEOROID_H_ */
