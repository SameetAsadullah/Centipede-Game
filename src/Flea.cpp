/*
 * Flea.cpp
 *
 *  Created on: May 5, 2019
 *      Author: sameet_asadullah
 */

#include "Flea.h"

Flea::Flea() :
		moveCount(0) {
	getP().setX(GetRandInRange(40, 960));
	getP().setY(740);
}

void Flea::Draw() {
	DrawCircle(getP().getX(), getP().getY(), 10, colors[BLUE]);
}

void Flea::Move() {
	moveCount++;
	getP().setY(getP().getY() - 10);

	if (moveCount > 4) {
		moveCount = 0;
	}
}

int Flea::getMoveCount() const {
	return moveCount;
}

void Flea::addMushroom(GameObject** m, int &TotalMushrooms) {
	if (getP().getY() < 680 && getP().getY() > 70) {
		m[TotalMushrooms]->getP().setY(getP().getY() - 10);
		m[TotalMushrooms]->getP().setX(getP().getX());
		TotalMushrooms++;
	}
}

Flea::~Flea() {
}

