/*
 * Mesh.cpp
 *
 *  Created on: Oct 4, 2014
 *      Author: amu
 */

#include "Mesh.h"

Mesh::Mesh() {
	vbo = 0;
	color = 0;
	draws = 0;
}

void Mesh::setVertices(float vertices[], float colors[]){
	glGenBuffers(1, &vbo);
	glGenBuffers(1, &color);

	draws = sizeof(vertices) / sizeof(float);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ARRAY_BUFFER, color);
	glBufferData(GL_ARRAY_BUFFER, sizeof(colors), colors, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Mesh::render(){
	glFrontFace(GL_CW);

//	glEnableClientState(GL_VERTEX_ARRAY);
//	glBindBuffer(GL_ARRAY_BUFFER, vbo);
//	glVertexPointer(3, GL_FLOAT, 0, 0);
//
//	glEnableClientState(GL_COLOR_ARRAY);
//	glBindBuffer(GL_ARRAY_BUFFER, color);
//	glColorPointer(4, GL_FLOAT, 0, 0);

	GLfloat vert[] = {-1, 0, 0, 0, 1, 0, 1, 0, 0};
	GLfloat col[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, vert);
	glEnableClientState(GL_COLOR_ARRAY);
	glColorPointer(4, GL_FLOAT, 0, col);
	glDrawArrays(GL_TRIANGLES, 0, 3);

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

Mesh::~Mesh() {
//	glDeleteBuffers(1, &vbo);
}

