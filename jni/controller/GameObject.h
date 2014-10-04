/*
 * GameObject.h
 *
 *  Created on: Oct 3, 2014
 *      Author: amu
 */

#include "Transform.h"
#include "../physics/Collider.h"

#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_

class GameObject {
public:
	Transform transform;
	Collider collider;

	GameObject();
	GameObject(const GameObject&);
	virtual ~GameObject();

	void render();
	void update();
};

#endif /* GAMEOBJECT_H_ */
