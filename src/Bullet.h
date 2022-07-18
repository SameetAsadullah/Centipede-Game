/*
 * Bullet.h
 *
 *  Created on: May 5, 2019
 *      Author: sameet_asadullah
 */

#ifndef BULLET_H_
#define BULLET_H_

#include"MoveableObject.h"

class Bullet: public MoveableObject {
public:
	Bullet();
	void Draw();
	void Move();
	virtual ~Bullet();
};

#endif /* BULLET_H_ */
