/*
 * GameObject.h
 *
 *  Created on: May 3, 2019
 *      Author: sameet_asadullah
 */

#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_

#include"Position.h"
#include"util.h"

class GameObject {
	Position p;
	int lives;

public:
	GameObject();
	GameObject(int X, int Y);
	Position& getP();
	virtual void Draw() = 0;
	void setLives(int l);
	int getLives() const;
	virtual ~GameObject();
};

#endif /* GAMEOBJECT_H_ */
