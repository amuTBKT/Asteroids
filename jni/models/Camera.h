/*
 * Camera.h
 *
 *  Created on: Oct 10, 2014
 *      Author: amu
 */

#ifndef CAMERA_H_
#define CAMERA_H_

#include "../controller/GameObject.h"
#include <GLES/gl.h>

class Camera : public GameObject{
public:
	float width, height, zNear, zFar;

	Camera(float, float);
	Camera(const Camera&);
	virtual ~Camera();
	void update();
	Collider getLeftBound();
	Collider getRightBound();
	Collider getBottomBound();
	Collider getTopBound();
private:
	Collider screen_bounds[4];
};

#endif /* CAMERA_H_ */
