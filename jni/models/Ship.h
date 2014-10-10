/*
 * Ship.h
 *
 *  Created on: Oct 10, 2014
 *      Author: amu
 */

#include "../controller/GameObject.h"
#include "Mesh.h"

#ifndef SHIP_H_
#define SHIP_H_

class Ship : public GameObject {
public:
	// graphics
	Mesh *mesh;

	Ship();
	virtual ~Ship();

	void createMesh();
	void update();
};

#endif /* SHIP_H_ */
