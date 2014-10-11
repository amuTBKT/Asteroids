/*
 * Collider.h
 *
 *  Created on: Oct 3, 2014
 *      Author: amu
 */

#ifndef COLLIDER_H_
#define COLLIDER_H_

#include "../core/Vector2.h"

class Collider {
public:
	Collider();
	Collider (const Collider&);
	virtual ~Collider();

	// bounding rectangle
	Vector2 position;
	struct aabb{
		float width;
		float height;
	} bounds;
	bool checkForCollision;

	void setBounds(float, float);
	void translate(const Vector2&);
	void translate(float, float);
	bool inBounds(const Vector2&);
	bool inBounds(float, float);
	bool testAABB(const Collider&);
};

#endif /* COLLIDER_H_ */
