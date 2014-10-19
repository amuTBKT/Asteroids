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

float Random::genRandomNumber(){
	return rand();
}

float Random::genRandomNumber(int from, int to){
	return rand() % to + from;
}

Random::~Random() {
}

