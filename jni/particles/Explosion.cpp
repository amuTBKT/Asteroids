/*
 * Explosion.cpp
 *
 *  Created on: Oct 20, 2014
 *      Author: amu
 */

#include "Explosion.h"

Explosion::Explosion() {
	numParticles = sizeof(particles) / sizeof(Vector2);
	time = 0;
	rotation = 0;
	isActive = false;

	for (int i = 0; i < numParticles; i++){
		particles[i] = Vector2(Random::genRandomFloat() * 8 * cosf(2 * M_PI * i / numParticles), Random::genRandomFloat() * 8 * sinf(2 * M_PI * i / numParticles));
	}
}

void Explosion::render(){
	if (!isActive) return;

	time += 0.05;

	if (time > 2.5) {
		reset();
	}

	GLfloat data[numParticles * 6];
	for (int i = 0; i < numParticles; i++){
		data[i * 6 + 0] = (particles[i] * Vector2(1, 0)) * time * 5;							// x1
		data[i * 6 + 1] = (particles[i] * Vector2(0, 1)) * time * 5;							// y1
		data[i * 6 + 2] = 0;																	// z1, always = 0
		data[i * 6 + 3] = (particles[i] * Vector2(1, 0)) * time * 5 + particles[i].x;			// x2
		data[i * 6 + 4] = (particles[i] * Vector2(0, 1)) * time * 5 + particles[i].y;			// y2
		data[i * 6 + 5] = 0;																	// z2, always = 0
	}

	glPushMatrix();
	glTranslatef(position.x, position.y, 0);
	glRotatef(rotation, 0, 0, 1);

	// draw here //
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, data);
	glDrawArrays(GL_LINES, 0, numParticles * 2);//sizeof(data) / sizeof(GLfloat));
	glDisableClientState(GL_VERTEX_ARRAY);
	///////////////

	glPopMatrix();

}

void Explosion::reset(){
	isActive = false;
	time = 0;
	rotation = -1 + 2 * (Random::genRandomFloat()) * 30;
}

Explosion::~Explosion() {
}

