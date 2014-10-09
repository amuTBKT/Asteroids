/*
 * GameObject.cpp
 *
 *  Created on: Oct 3, 2014
 *      Author: amu
 */

#include "GameObject.h"

GameObject::GameObject() {
	transform = Transform();
	collider = Collider();
}

GameObject::GameObject(const GameObject& g) {
	collider = g.collider;
	transform = g.transform;
}

void GameObject::render(){
	update();
}

void GameObject::update(){
	transform.translate(transform.velocity);
	collider.position = transform.position;
}

GameObject::~GameObject() {
}

