/*
 * MovingEntity.h
 *
 *  Created on: Oct 9, 2014
 *      Author: amu
 */

#include "GameObject.h"

#ifndef MOVINGENTITY_H_
#define MOVINGENTITY_H_

class MovingEntity : public GameObject {
public:
	Vector2 velocity, acceletaion;

	MovingEntity();
	virtual ~MovingEntity();

	void move();
};

#endif /* MOVINGENTITY_H_ */
