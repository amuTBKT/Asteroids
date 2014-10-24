/*
 * LifeStatus.h
 *
 *  Created on: Oct 24, 2014
 *      Author: amu
 */

#ifndef LIFESTATUS_H_
#define LIFESTATUS_H_

#include "Mesh.h"
#include "../core/Vector2.h"
#include "../controller/GameController.h"

class LifeStatus {
public:
	Vector2 position;

	LifeStatus(float);
	virtual ~LifeStatus();

	void init();
	void render();
	void kill();
	bool isDead();

private:
	Mesh *mesh;
	int maxLife, minLife, life;
	float scale;

	void createMesh(float scl){
		float data[4 * 3];
		float scaleX = scl, scaleY = scl;
		data[1] =  scaleX;			data[0]  = 0;			data[2]  = 0;
		data[4] = -scaleX;			data[3]  = scaleY;		data[5]  = 0;
		data[7] = -scaleX / 2;		data[6]  = 0;			data[8]  = 0;
		data[10] = -scaleX;			data[9] = -scaleY;		data[11] = 0;

		mesh = new Mesh();
		mesh->setVertices(&data[0], sizeof(data) / sizeof(float), false);
	}
};

#endif /* LIFESTATUS_H_ */
