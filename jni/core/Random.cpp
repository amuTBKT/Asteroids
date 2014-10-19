/*
 * Random.cpp
 *
 *  Created on: Oct 19, 2014
 *      Author: amu
 */

#include "Random.h"

Random::Random() {
	srand(time(NULL));
}

float Random::genRandomNumber(int from, int to){
	return rand() % to + from;
}

float Random::genRandomFloat(){
	return (float) rand() / (float) RAND_MAX;
}

Vector2 Random::genRandomVector2(float lenght){
	Vector2 v(-1 + 2 * (float) rand() / (float) RAND_MAX, -1 + 2 * (float) rand() / (float) RAND_MAX);
	v.normalize();
	return v * lenght;
}

Random::~Random() {
}

