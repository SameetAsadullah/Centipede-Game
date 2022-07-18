/*
 * Mushroom.cpp
 *
 *  Created on: May 4, 2019
 *      Author: sameet_asadullah
 */

#include "Mushroom.h"

Mushroom::Mushroom(){
	getP().setX(GetRandInRange(30, 980));
	getP().setY(GetRandInRange(70, 680));
	setLives(2);
}

void Mushroom::Draw() {
	DrawSquare(getP().getX(), getP().getY(), 16, colors[GOLD]);
	DrawCircle(getP().getX()+8, getP().getY() + 20, 4, colors[RED]);
}

Mushroom::~Mushroom() {
}

