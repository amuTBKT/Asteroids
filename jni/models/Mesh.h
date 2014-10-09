/*
 * Mesh.h
 *
 *  Created on: Oct 4, 2014
 *      Author: amu
 */

#include <GLES/gl.h>

#ifndef MESH_H_
#define MESH_H_

class Mesh {
public:
	// member variables
	GLuint vbo, color;
	int draws;

	Mesh();
	virtual ~Mesh();

	void setVertices(float[], float[]);
	void render();
};

#endif /* MESH_H_ */
