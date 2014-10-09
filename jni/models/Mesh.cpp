/*
 * Mesh.cpp
 *
 *  Created on: Oct 4, 2014
 *      Author: amu
 */

#include "Mesh.h"

Mesh::Mesh() {
	draws = 0;
	vbo = 0;

	float data[] = {-1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 1, 1};

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(data), data, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Mesh::setVertices(const float data[]){
	draws = sizeof(data) / sizeof(float);

//	glGenBuffers(1, &vbo);
//	glBindBuffer(GL_ARRAY_BUFFER, vbo);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(data), data, GL_STATIC_DRAW);
//	glBindBuffer(GL_ARRAY_BUFFER, 0);

}

void Mesh::render(){
	glFrontFace(GL_CW);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);

	glVertexPointer(3, GL_FLOAT, 7 * sizeof(float), 0);
	glColorPointer(4, GL_FLOAT, 7 * sizeof(float), (void*)(3 * sizeof(float)));
	glDrawArrays(GL_TRIANGLES, 0, 3);

	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

Mesh::~Mesh() {
//	glDeleteBuffers(1, &vbo);
}

