/*
 * Collider.h
 *
 *  Created on: Oct 3, 2014
 *      Author: amu
 */

#include "Vector2.h"

#ifndef COLLIDER_H_
#define COLLIDER_H_

class Collider {
public:
	Collider();
	virtual ~Collider();

	// bounding rectangle
	struct aabb{
		float minX;
		float maxX;
		float minY;
		float maxY;
	} *bounds;
	void setBounds(float, float, float, float);

	bool inBounds(Vector2 point);
	bool inBounds(float, float);
};

#endif /* COLLIDER_H_ */
