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
#include <vector>

class MeteoroidManager {
public:
	int capacity, sActiveMeteors, bActiveMeteors;
	std::vector<Meteoroid> sMeteoroids, bMeteoroids;

	MeteoroidManager();
	virtual ~MeteoroidManager();

	void init();
	void update();
	void genNewMeteoroid(int, Vector2, Vector2);
	void genCirclePattern(Vector2);
	void spawnMeteoroid(int);

	bool checkForCollison(std::vector<Bullet>&);
private:
	int activeSMeteors(){
		int counter = 0;
		for (int i = 0; i < counter; i++){
			if (sMeteoroids[i].isActive) ++counter;
		}
		return counter;
	}
	int activeBMeteors(){
		int counter = 0;
		for (int i = 0; i < counter / 2; i++){
			if (bMeteoroids[i].isActive) ++counter;
		}
		return counter;
	}
};

#endif /* METEOROIDMANAGER_H_ */
