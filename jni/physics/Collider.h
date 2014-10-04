/*
 * Collider.h
 *
 *  Created on: Oct 3, 2014
 *      Author: amu
 */

#include "../core/Vector2.h"

#ifndef COLLIDER_H_
#define COLLIDER_H_

class Collider {
public:
	Collider();
	Collider (const Collider&);
	virtual ~Collider();

	// bounding rectangle
//	GameObject parent;
	struct aabb{
		float minX;
		float maxX;
		float minY;
		float maxY;
	} *bounds;

//	void setParent(const GameObject&);
	void setBounds(float, float, float, float);
	void translate(const Vector2&);
	void translate(float, float);
	bool inBounds(const Vector2& point);
	bool inBounds(float, float);
	bool testAABB(const Collider&);
};

#endif /* COLLIDER_H_ */
