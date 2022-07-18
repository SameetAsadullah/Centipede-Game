/*
 * Segment.cpp
 *
 *  Created on: May 4, 2019
 *      Author: sameet_asadullah
 */

#include "Segment.h"

Segment::Segment():color(0) {
}

Position& Segment::getSegment() {
	return segment;
}

long Segment::getColor() const {
	return color;
}

void Segment::setColor(long c) {
	color = c;
}

void Segment::draw() {
}

Segment::~Segment() {
}

