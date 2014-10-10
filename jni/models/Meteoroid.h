/*
 * Meteoroid.h
 *
 *  Created on: Oct 9, 2014
 *      Author: amu
 */

#include <math.h>
#include "../controller/MovingEntity.h"

#ifndef METEOROID_H_
#define METEOROID_H_

class Meteoroid : public MovingEntity{
public:
	// graphics
	float radius;

	Meteoroid(float);
	virtual ~Meteoroid();
	void update();

protected:
	void createMesh(int);
};

#endif /* METEOROID_H_ */
