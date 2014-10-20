/*
 * Explosion.h
 *
 *  Created on: Oct 20, 2014
 *      Author: amu
 */

#ifndef EXPLOSION_H_
#define EXPLOSION_H_

#include <GLES/gl.h>
#include "../core/Vector2.h"
#include "../core/Random.h"

class Explosion {
public:
	int numParticles;
	float time, rotation;
	Vector2 position;
	Vector2 particles[20];
	bool isActive;

	Explosion();
	virtual ~Explosion();

	void render();
	void reset();
};

#endif /* EXPLOSION_H_ */
