/*
 * Camera.h
 *
 *  Created on: Oct 10, 2014
 *      Author: amu
 */

#include "../controller/GameObject.h"
#include <GLES/gl.h>

#ifndef CAMERA_H_
#define CAMERA_H_

class Camera : public GameObject{
public:
	float width, height, zNear, zFar;

	Camera(float, float);
	virtual ~Camera();
	void update();
};

#endif /* CAMERA_H_ */
