/*
 * GameObject.cpp
 *
 *  Created on: Oct 3, 2014
 *      Author: amu
 */

#include <GLES/gl.h>
#include "GameObject.h"

GameObject::GameObject() {
}

GameObject::GameObject(const GameObject& g) {
	collider = g.collider;
	transform = g.transform;
}

void GameObject::render(){
	update();
}

void GameObject::update(){
	collider.position = transform.position;
}

GameObject::~GameObject() {
}

