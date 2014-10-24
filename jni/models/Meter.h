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
	Vector2 position;

	Meter(float);
	virtual ~Meter();

	void init();
	void startUsingMeter();
	void fillMeter();
	void useMeter(float);
	bool isEmpty();
	void render();
	void update();

private:
	Mesh *border, *bar;
	float scaleX, scaleY, value;
	bool usingMeter;

	void crateMesh(float scale){
		float borderOffset = scaleY / 5;
		float borderData[12] = 	{
									-scaleX - borderOffset, -scaleY - borderOffset, 0,
									-scaleX - borderOffset,  scaleY + borderOffset, 0,
									 scaleX + borderOffset,  scaleY + borderOffset, 0,
									 scaleX + borderOffset, -scaleY - borderOffset, 0
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
