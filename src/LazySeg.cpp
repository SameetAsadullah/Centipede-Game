/*
 * LazySeg.cpp
 *
 *  Created on: May 4, 2019
 *      Author: sameet_asadullah
 */

#include "LazySeg.h"

LazySeg::LazySeg() {
}

void LazySeg::draw() {
	DrawCircle(getSegment().getX(), getSegment().getY(), 10, colors[RED]);
}
LazySeg::~LazySeg() {
}

