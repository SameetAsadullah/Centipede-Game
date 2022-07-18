/*
 * Bullet.cpp
 *
 *  Created on: May 5, 2019
 *      Author: sameet_asadullah
 */

#include "Bullet.h"

Bullet::Bullet() {
	getP().setX(0);
	getP().setY(0);
}

void Bullet::Draw() {
	if (getP().getY() < 740 && getP().getY() != 0) {
		DrawLine(getP().getX(), getP().getY() - 20, getP().getX(),
				getP().getY()+10, 4, colors[ORANGE]);
	}
}

void Bullet::Move() {
	if (getP().getY() < 740 && getP().getY() != 0) {
		getP().setY(getP().getY() + 10);
	}
}

Bullet::~Bullet() {
}

