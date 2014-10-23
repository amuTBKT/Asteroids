/*
 * Meter.h
 *
 *  Created on: Oct 23, 2014
 *      Author: amu
 */

#ifndef METER_H_
#define METER_H_

#include "Mesh.h"
#include "../core/Vector2.h"

class Meter {
public:
	Mesh *border, *bar;
	Vector2 position;

	Meter();
	virtual ~Meter();

	void init();
	void render();

private:
	void crateMesh(float scale){
		float scaleX = 2.5 * scale, scaleY = scale / 2;
		float borderData[12] = 	{
									-scaleX, -scaleY, 0,
									-scaleX,  scaleY, 0,
									 scaleX,  scaleY, 0,
									 scaleX, -scaleY, 0
								};
		border = new Mesh();
		border->setVertices(&borderData[0], sizeof(borderData) / sizeof(float), false);


		float barData[18] =	{
								-2 * scaleX, -scaleY, 0,
								-2 * scaleX,  scaleY, 0,
								 0 * scaleX,  scaleY, 0,
								 0 * scaleX,  scaleY, 0,
								 0 * scaleX, -scaleY, 0,
								-2 * scaleX, -scaleY, 0
							};
		bar =  new Mesh();
		bar->setVertices(&barData[0], sizeof(barData) / sizeof(float), false);

	}
};

#endif /* METER_H_ */
