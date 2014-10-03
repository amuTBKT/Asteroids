/*
 * Vector2.cpp
 *
 *  Created on: Oct 3, 2014
 *      Author: amu
 */

#include "Vector2.h"

Vector2::Vector2(float m = 0, float n = 0):x(m), y(n){}
Vector2::Vector2():x(0), y(0){}

void Vector2::set(float m, float n){
	x = m;
	y = n;
}

void Vector2::setX(float m){
	x = m;
}

void Vector2::setY(float n){
	y = n;
}

