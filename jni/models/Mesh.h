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
	int draws, stride;

	Mesh();
	virtual ~Mesh();

	void setVertices(float*, int, bool);
	void render();
};

#endif /* MESH_H_ */
