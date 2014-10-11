/*
 * Bullet.h
 *
 *  Created on: Oct 10, 2014
 *      Author: amu
 */

#ifndef BULLET_H_
#define BULLET_H_

#include "../controller/MovingEntity.h"

class Bullet : public MovingEntity{
public:
	float radius;

	Bullet(float);
	Bullet(float, const Vector2&);
	virtual ~Bullet();

	void upate();
	void reset();
protected:
	void createMesh(int);
};

#endif /* BULLET_H_ */
