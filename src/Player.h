/*
 * Player.h
 *
 *  Created on: May 4, 2019
 *      Author: sameet_asadullah
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include"MoveableObject.h"

class Player: public MoveableObject {
public:
	Player();
	void Draw();
	void Move();
	virtual ~Player();
};

#endif /* PLAYER_H_ */
