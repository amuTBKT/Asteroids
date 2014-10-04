/*
 * CircleCollider.h
 *
 *  Created on: Oct 4, 2014
 *      Author: amu
 */

#include "Collider.h"

#ifndef CIRCLECOLLIDER_H_
#define CIRCLECOLLIDER_H_

// minX, minY => position
// maxX = maxY = radius

class CircleCollider : public Collider{
public:
	CircleCollider();
	virtual ~CircleCollider();

	void setRadius(float);
};

#endif /* CIRCLECOLLIDER_H_ */
