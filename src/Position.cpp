/*
 * Position.cpp
 *
 *  Created on: May 3, 2019
 *      Author: sameet_asadullah
 */

#include "Position.h"

Position::Position() :
		x(0), y(0) {
}

Position::Position(int X, int Y) :
		x(X), y(Y) {
}

void Position::setX(int X) {
		x = X;
}

int Position::getX() const {
	return x;
}

void Position::setY(int Y) {
	y = Y;
}

int Position::getY() const {
	return y;
}

Position::~Position() {
}

