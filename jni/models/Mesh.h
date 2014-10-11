/*
 * Mesh.h
 *
 *  Created on: Oct 4, 2014
 *      Author: amu
 */

#ifndef MESH_H_
#define MESH_H_

#include <GLES/gl.h>

class Mesh {
public:
	// member variables
	GLuint vbo;
	int draws, stride;

	Mesh();
	virtual ~Mesh();

	void setVertices(float*, int, bool);
	void render(int);
};

#endif /* MESH_H_ */
