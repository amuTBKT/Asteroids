/*
 * Random.h
 *
 *  Created on: Oct 19, 2014
 *      Author: amu
 */

#ifndef RANDOM_H_
#define RANDOM_H_

#include <stdlib.h>
#include <time.h>
#include "Vector2.h"

class Random {
public:
	Random();
	virtual ~Random();

	static float genRandomNumber(int, int);
	static float genRandomFloat();
	static Vector2 genRandomVector2(float);
};

#endif /* RANDOM_H_ */
