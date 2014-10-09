/*
 * Meteoroid.h
 *
 *  Created on: Oct 9, 2014
 *      Author: amu
 */

#include "../controller/MovingEntity.h"
#include "Mesh.h"

#ifndef METEOROID_H_
#define METEOROID_H_

class Meteoroid : public MovingEntity{
public:
	// graphics
	Mesh* mesh;
	float radius;

	Meteoroid(float);
	virtual ~Meteoroid();
	void update();

private:
	void createMesh(int);
};

#endif /* METEOROID_H_ */
