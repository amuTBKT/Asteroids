/*
 * Mesh.cpp
 *
 *  Created on: Oct 4, 2014
 *      Author: amu
 */

#include "Mesh.h"

Mesh::Mesh() {
	draws = 0;
	stride = 0;
	vbo = 0;
}

void Mesh::setVertices(float* p, int length, bool hasColor){
	float data[length];
	for (int i = 0; i < length; i++){
		data[i] = *p;
		p++;
	}

	// generate vertex buffer for efficient rendering
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(data), data, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	// initialize the draw counts
	draws = sizeof(data) / sizeof(float);
	if (hasColor) {
		draws /= 7;
		stride = 7;
	}
	else {
		draws /= 3;
		stride = 0;
	}
}

void Mesh::render(){
	glFrontFace(GL_CW);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);

	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, stride * sizeof(float), 0);

	// check whether vbo has color data
	if (stride > 0) {
		glEnableClientState(GL_COLOR_ARRAY);
		glColorPointer(4, GL_FLOAT, stride * sizeof(float), (void*)(3 * sizeof(float)));
	}

	glDrawArrays(GL_LINE_LOOP, 0, draws);

	if (stride > 0)	glDisableClientState(GL_COLOR_ARRAY); // disable color array if vbo has color data
	glDisableClientState(GL_VERTEX_ARRAY);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

Mesh::~Mesh() {
//	glDeleteBuffers(1, &vbo);
}

