/*
 * MovingEntity.h
 *
 *  Created on: Oct 9, 2014
 *      Author: amu
 */

#ifndef MOVINGENTITY_H_
#define MOVINGENTITY_H_

#include "GameObject.h"
#include "../core/GLOBALVAR.h"
#include "../models/Mesh.h"

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
