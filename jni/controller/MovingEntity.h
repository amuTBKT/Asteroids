/*
 * MovingEntity.h
 *
 *  Created on: Oct 9, 2014
 *      Author: amu
 */

#include "GameObject.h"
#include "../models/Mesh.h"

#ifndef MOVINGENTITY_H_
#define MOVINGENTITY_H_

class MovingEntity : public GameObject {
public:
	// graphics
	Mesh *mesh;

	MovingEntity();
	virtual ~MovingEntity();
	virtual void update();

protected:
	void createMesh(int);
};

#endif /* MOVINGENTITY_H_ */
