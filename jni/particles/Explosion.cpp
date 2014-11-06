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
	size = 8;
}

void Explosion::init(){
	for (int i = 0; i < numParticles; i++){
		particles[i] = Vector2(Random::genRandomFloat() * size * cosf(2 * M_PI * i / numParticles), Random::genRandomFloat() * size * sinf(2 * M_PI * i / numParticles));
	}
}

void Explosion::render(){
	if (!isActive) return;

	time += 0.05;

	GLfloat data[numParticles * 6];
	for (int i = 0; i < numParticles; i++){ // move particles radially outward
		float x = (particles[i] * Vector2(1, 0)) * time * 5;
		float y = (particles[i] * Vector2(0, 1)) * time * 5;
		data[i * 6 + 0] = x;							// x1
		data[i * 6 + 1] = y;							// y1
		data[i * 6 + 2] = 0;							// z1, always = 0
		data[i * 6 + 3] = x + particles[i].x;			// x2
		data[i * 6 + 4] = y + particles[i].y;			// y2
		data[i * 6 + 5] = 0;							// z2, always = 0
	}

	glPushMatrix();
	glTranslatef(position.x, position.y, 0);
	glRotatef(rotation, 0, 0, 1);

	// drawing particles //
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, data);
	glDrawArrays(GL_LINES, 0, numParticles * 2);//sizeof(data) / sizeof(GLfloat));
	glDisableClientState(GL_VERTEX_ARRAY);
	///////////////////////

	glPopMatrix();

	if (time > 2.5) { // particle life = 2.5
		reset();
	}
}

void Explosion::reset(){
	isActive = false;
	time = 0;
	rotation = -1 + 2 * (Random::genRandomFloat()) * 30;
}

Explosion::~Explosion() {
}

