/*
 * MagicSeg.cpp
 *
 *  Created on: May 4, 2019
 *      Author: sameet_asadullah
 */

#include "MagicSeg.h"

MagicSeg::MagicSeg() :
		count(0) {
}

void MagicSeg::draw() {
	count++;
	if (count > 200 && count <= 500) {
		setColor(GetRandInRange(0, 100));
		DrawCircle(getSegment().getX(), getSegment().getY(), 10,
				colors[getColor()]);

		if (count == 500) {
			count = 0;
		}
	}

	else {
		DrawCircle(getSegment().getX(), getSegment().getY(), 10, colors[RED]);
	}
}

MagicSeg::~MagicSeg() {
}

