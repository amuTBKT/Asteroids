/*
 * Vector2.h
 *
 *  Created on: Oct 3, 2014
 *      Author: amu
 */

#include <math.h>

#ifndef VECTOR2_H_
#define VECTOR2_H_

class Vector2{
	public:
		// member variables
		float x, y;

		// constructor
		Vector2(float, float);
		Vector2();
		Vector2(const Vector2&);

		// getters and setters
		void set(float, float);
		void setX(float);
		void setY(float);
		void setLength(float lenght);
		void setAngle(float angle);
		float getX();
		float getY();
		float getLengthSQR();
		float getLength();
		float getAngle();

		// methods
		Vector2& operator=(const Vector2&);
		Vector2 operator +(const Vector2&);
		Vector2& operator +=(const Vector2&);
		Vector2 operator -(const Vector2&);
		Vector2& operator -=(const Vector2&);
		Vector2 operator *(float c);
		Vector2& operator *=(float c);
		Vector2 operator /(float c);
		Vector2& operator /=(float c);
		bool operator ==(const Vector2&);
		float operator *(const Vector2&); // dot operation
		void reverse();
		void truncate(float);
		void normalize();
		bool isNormalized();
		float angleBetween(const Vector2);
		float distanceBetween(const Vector2);
};

#endif /* VECTOR2_H_ */
