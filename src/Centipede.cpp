/*
 * Centipede.cpp
 *
 *  Created on: May 3, 2019
 *      Author: sameet_asadullah
 */

#include "Centipede.h"

Centipede::Centipede(float X, float Y) :
		leftCollision(false), rightCollision(false), upwardMotion(false), totalSegments(
				7) {

	segments = new Segment*[7];
	segments[0] = new MagicSeg;

	for (int i = 1; i < 7; i++) {
		segments[i] = new LazySeg;
	}

	segments[0]->getSegment().setX(X);
	segments[0]->getSegment().setY(Y);

	for (int i = 1; i < 7; i++) {
		segments[i]->getSegment().setY(Y);
		X += 20;
		segments[i]->getSegment().setX(X);
	}
}

void Centipede::Draw() {
	for (int i = 0; i < totalSegments; i++) {
		segments[i]->draw();
	}
}

void Centipede::MoveSegments() {
	int prev_X = segments[0]->getSegment().getX();
	int prev_Y = segments[0]->getSegment().getY();
	int prev_X1, prev_Y1;

	for (int i = 1; i < totalSegments; i++) {
		if (segments[i]->getSegment().getX() != -100) {
			prev_X1 = segments[i]->getSegment().getX();
			prev_Y1 = segments[i]->getSegment().getY();
			segments[i]->getSegment().setX(prev_X);
			segments[i]->getSegment().setY(prev_Y);
			prev_X = prev_X1;
			prev_Y = prev_Y1;
		}
	}
}

void Centipede::Move() {
	MoveSegments();

	if (segments[0]->getSegment().getY() > 0 && upwardMotion == false) {
		if (segments[0]->getSegment().getX() > 0
				&& ((leftCollision == false && rightCollision == false)
						|| rightCollision == true)) {
			segments[0]->getSegment().setX(
					segments[0]->getSegment().getX() - 20);
		}

		if (segments[0]->getSegment().getX() <= 0) {
			leftCollision = true;
			rightCollision = false;
			segments[0]->getSegment().setY(
					segments[0]->getSegment().getY() - 20);
		}

		if (segments[0]->getSegment().getX() >= 1000) {
			rightCollision = true;
			leftCollision = false;
			segments[0]->getSegment().setY(
					segments[0]->getSegment().getY() - 20);
		}

		if (leftCollision && segments[0]->getSegment().getX() < 1000) {
			if (segments[0]->getSegment().getY() == 140) {
				segments[0]->getSegment().setY(120);
			}
			segments[0]->getSegment().setX(
					segments[0]->getSegment().getX() + 20);
		}
	}

	if (segments[0]->getSegment().getY() == 0 || upwardMotion == true) {
		upwardMotion = true;

		if (segments[0]->getSegment().getY() <= 0) {
			leftCollision = false;
			rightCollision = false;
		}

		if (rightCollision && segments[0]->getSegment().getX() > 0) {
			segments[0]->getSegment().setX(
					segments[0]->getSegment().getX() - 20);
		}

		if (segments[0]->getSegment().getX() >= 1000) {
			leftCollision = false;
			rightCollision = true;
			segments[0]->getSegment().setY(
					segments[0]->getSegment().getY() + 20);
		}

		if (leftCollision && segments[0]->getSegment().getX() <= 1000) {
			segments[0]->getSegment().setX(
					segments[0]->getSegment().getX() + 20);
		}

		if (!leftCollision && !rightCollision) {
			segments[0]->getSegment().setY(40);
			leftCollision = true;
		}

		if (segments[0]->getSegment().getX() <= 0) {
			leftCollision = true;
			rightCollision = false;
			segments[0]->getSegment().setY(
					segments[0]->getSegment().getY() + 20);
			segments[0]->getSegment().setX(20);
		}

		if (segments[0]->getSegment().getY() == 140) {
			upwardMotion = false;
			segments[0]->getSegment().setY(100);
			leftCollision = false;
			rightCollision = true;
		}
	}
}

bool Centipede::isLeftCollision() const {
	return leftCollision;
}

void Centipede::setTotalSegments(int s) {
	totalSegments = s;
}

int Centipede::getTotalSegments() const {
	return totalSegments;
}

bool Centipede::isRightCollision() const {
	return rightCollision;
}

void Centipede::setLeftCollision(bool lc) {
	leftCollision = lc;
}

void Centipede::setRightCollision(bool rc) {
	rightCollision = rc;
}

Segment * *&Centipede::getSegment() {
	return segments;
}

void Centipede::addMushrooms(GameObject** m, int &TotalMushrooms, int X, int Y) {
	m[TotalMushrooms]->getP().setY(Y);
	m[TotalMushrooms]->getP().setX(X);
	TotalMushrooms++;
}

Centipede::~Centipede() {
}

