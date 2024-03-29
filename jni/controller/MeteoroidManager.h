/*
 * MeteoroidManager.h
 *
 *  Created on: Oct 16, 2014
 *      Author: amu
 */

#ifndef METEOROIDMANAGER_H_
#define METEOROIDMANAGER_H_

#include "../core/GLOBALVAR.h"
#include "../core/Random.h"
#include "../models/Meteoroid.h"
#include "../models/Bullet.h"
#include "../models/Ship.h"
#include "ExplosionManager.h"
#include <vector>

class MeteoroidManager {
public:
	int capacity, sActiveMeteors, bActiveMeteors;
	float speed;
	std::vector<Meteoroid> sMeteoroids, bMeteoroids;
	Ship *pShip;
	Explosion *shipExp;
	ExplosionManager *expManager;

	// for communicating with HuD //
	static bool decLife;
	////////////////////////////////

	MeteoroidManager();
	virtual ~MeteoroidManager();

	void init();
	void update(Ship&);
	void genNewMeteoroid(int, Vector2, Vector2);
	void genCirclePattern(Vector2);
	void spawnMeteoroid(int);

	bool checkForCollison(std::vector<Bullet>&);
private:
	bool checkForBounds(Vector2 *pos, Vector2 *vel){
		if (pos->x > GLOBAL_VAR::SCREEN_WIDTH && vel->x > 0) {
			return true;
		}
		if (pos->x < 0 && vel->x < 0) {
			return true;
		}
		if (pos->y > GLOBAL_VAR::SCREEN_HEIGHT && vel->y > 0) {
			return true;
		}
		if (pos->y < 0 && vel->y < 0) {
			return true;
		}
		return false;
	}
	void resetShip(){
		pShip->transform.position.set(50, 240);
		pShip->transform.velocity.set(0, 0);
		pShip->isActive = false;
	}
};

#endif /* METEOROIDMANAGER_H_ */
