/*
 * Mesh.h
 *
 *  Created on: Oct 4, 2014
 *      Author: amu
 */

#include <GLES/gl.h>
#include <stdlib.h>

#ifndef MESH_H_
#define MESH_H_

class Mesh {
public:
	// member variables
	GLuint vbo;
	int draws;

	Mesh();
	virtual ~Mesh();

	void setVertices(const float[]);
	void render();
};

#endif /* MESH_H_ */
