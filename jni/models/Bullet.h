/*
 * Bullet.h
 *
 *  Created on: Oct 10, 2014
 *      Author: amu
 */

#include "../controller/MovingEntity.h"

#ifndef BULLET_H_
#define BULLET_H_

class Bullet : public MovingEntity{
public:
	float radius;

	Bullet(float);
	virtual ~Bullet();

protected:
	void createMesh(int);
};

#endif /* BULLET_H_ */
