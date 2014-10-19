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

class Random {
public:
	Random();
	virtual ~Random();

	static float genRandomNumber();
	static float genRandomNumber(int, int);
};

#endif /* RANDOM_H_ */
