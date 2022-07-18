/*
 * Mushroom.h
 *
 *  Created on: May 4, 2019
 *      Author: sameet_asadullah
 */

#ifndef MUSHROOM_H_
#define MUSHROOM_H_

#include"GameObject.h"

class Mushroom:public GameObject {
public:
	Mushroom();
	void Draw();
	virtual ~Mushroom();
};

#endif /* MUSHROOM_H_ */
