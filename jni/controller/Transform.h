/*
 * Transform.h
 *
 *  Created on: Oct 3, 2014
 *      Author: amu
 */

#include "../core/Vector2.h"

#ifndef TRANSFORM_H_
#define TRANSFORM_H_

class Transform {
public:
	Transform();
	Transform(const Transform&);
	Transform(Vector2, Vector2, float);
	virtual ~Transform();

	// member variables
	Vector2 position, scale, velocity;
	float rotation;

	// methods
	void setVelocity(const Vector2&);
	void setPosition(const Vector2&);
	void translate(Vector2);
	void translate(float, float);
	void setScale(const Vector2&);
	void changeScale(Vector2);
	void changeScale(float, float);
	void setRotation(float);
	void rotate(float);
};

#endif /* TRANSFORM_H_ */
