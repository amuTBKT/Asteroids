/*
 * MeteoroidManager.h
 *
 *  Created on: Oct 16, 2014
 *      Author: amu
 */

#ifndef METEOROIDMANAGER_H_
#define METEOROIDMANAGER_H_

#include "../core/GLOBALVAR.h"
#include "../models/Meteoroid.h"
#include <vector>

class MeteoroidManager {
public:
	int capacity;
	std::vector<Meteoroid> sMeteoroids, bMeteoroids;

	MeteoroidManager();
	virtual ~MeteoroidManager();

	void init();
	void update();
	void genNewMeteoroid(int, Vector2, Vector2);
	void genCirclePattern(Vector2);
};

#endif /* METEOROIDMANAGER_H_ */
