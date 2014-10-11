/*
 * GameObject.h
 *
 *  Created on: Oct 3, 2014
 *      Author: amu
 */

#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_

#include "Transform.h"
#include "../physics/Collider.h"

class GameObject {
public:
	Transform transform;
	Collider collider;

	GameObject();
	GameObject(const GameObject&);
	virtual ~GameObject();

	void render();
	virtual void update();
};

#endif /* GAMEOBJECT_H_ */
