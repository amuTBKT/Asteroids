/*
 * Collider.h
 *
 *  Created on: Oct 3, 2014
 *      Author: amu
 */

#ifndef COLLIDER_H_
#define COLLIDER_H_

#include "../core/Vector2.h"
#include <GLES/gl.h>

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
	struct collidedWithCameraBound{
		int h, v;
	} cWCameraBound;

	void render();
	void renderAsSphere();

	void setBounds(float, float);
	void translate(const Vector2&);
	void translate(float, float);
	bool inBounds(const Vector2&);
	bool inBounds(float, float);
	bool testAABB(const Collider&);
	bool testSphere(const Collider&);
};

#endif /* COLLIDER_H_ */
