/*
 * Meteoroid.h
 *
 *  Created on: Oct 9, 2014
 *      Author: amu
 */

#include "../controller/GameObject.h"
#include "Mesh.h"

#ifndef METEOROID_H_
#define METEOROID_H_

class Meteoroid : public GameObject{
public:
	// graphics
	Mesh* mesh;
	float radius;

	Meteoroid(float);
	virtual ~Meteoroid();
private:
	void createMesh(int);
};

#endif /* METEOROID_H_ */
