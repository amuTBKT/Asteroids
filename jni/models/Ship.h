/*
 * Ship.h
 *
 *  Created on: Oct 10, 2014
 *      Author: amu
 */

#ifndef SHIP_H_
#define SHIP_H_

#include "../controller/MovingEntity.h"
#include "../controller/BulletManager.h"
#include "../core/FileLoader.h"

class Ship : public MovingEntity {
public:
	BulletManager bulletManager;
	bool isActive;

	Ship(int);
	virtual ~Ship();

	void update();
	void shoot();

protected:
	void createMesh(int);
private:
	void checkForBounds(){
		Vector2 *pos = &transform.position;
		if (pos->x > GLOBAL_VAR::SCREEN_WIDTH) pos->x -= GLOBAL_VAR::SCREEN_WIDTH;
		if (pos->x < 0) pos->x += GLOBAL_VAR::SCREEN_WIDTH;
		if (pos->y > GLOBAL_VAR::SCREEN_HEIGHT) pos->y -= GLOBAL_VAR::SCREEN_HEIGHT;
		if (pos->y < 0) pos->y += GLOBAL_VAR::SCREEN_HEIGHT;
		delete pos;
	}
};

#endif /* SHIP_H_ */
