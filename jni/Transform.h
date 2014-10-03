/*
 * Transform.h
 *
 *  Created on: Oct 3, 2014
 *      Author: amu
 */

#include "Vector2.h"

#ifndef TRANSFORM_H_
#define TRANSFORM_H_

class Transform {
public:
	Transform();
	Transform(Vector2, Vector2, float);
	virtual ~Transform();

	// member variables
	Vector2 position, scale;
	float rotation;

	// methods
	void setPosition(Vector2);
	void translate(Vector2);
	void translate(float, float);
	void setScale(Vector2);
	void changeScale(Vector2);
	void changeScale(float, float);
	void setRotation(float);
	void rotate(float);
};

#endif /* TRANSFORM_H_ */
