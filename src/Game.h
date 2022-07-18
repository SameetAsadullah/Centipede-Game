/*
 * Game.h
 *
 *  Created on: May 4, 2019
 *      Author: sameet_asadullah
 */

#ifndef GAME_H_
#define GAME_H_

#include"Centipede.h"
#include"Mushroom.h"
#include"Player.h"
#include"Bullet.h"
#include"Flea.h"
#include"ScoreBoard.h"

class Game {
public:
	MoveableObject** ptr;
	GameObject** ptr1;
	Flea f;
	Centipede c;
	Centipede c1;
	ScoreBoard sb;
	int tMushrooms, count, drawMushroom, oldMushrooms, pauseGame, body;
	bool endGame, splittingOfCentipede, menuWorking;
	Game();
	void DrawMushroom();
	void CheckMushroom();
	void collisionWithBulletAndMushroom();
	void checkFlea();
	void collisionWithBulletAndFlea();
	void collisionWithMushroomAndCentipede();
	void collisionWithFleaAndPlayer();
	void collisionWithCentipedeAndPlayer();
	void splitting();
	void collisionWithCentipedeAndBullet();
	virtual ~Game();
};

#endif /* GAME_H_ */
