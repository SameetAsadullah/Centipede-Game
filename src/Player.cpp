/*
 * Player.cpp
 *
 *  Created on: May 4, 2019
 *      Author: sameet_asadullah
 */

#include "Player.h"

Player::Player() {
	getP().setX(475);
	getP().setY(20);
	setLives(3);
}

void Player::Draw() {
	DrawRoundRect(getP().getX(), getP().getY(), 50, 10, colors[BLUE], 5);
	DrawCircle(getP().getX() + 25, getP().getY() + 15, 5, colors[RED]);
}

void Player::Move() {
}

Player::~Player() {
}

