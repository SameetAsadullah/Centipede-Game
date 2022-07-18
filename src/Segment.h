/*
 * Segment.h
 *
 *  Created on: May 4, 2019
 *      Author: sameet_asadullah
 */

#ifndef SEGMENT_H_
#define SEGMENT_H_

#include"Position.h"

class Segment {
	Position segment;
	long color;

public:
	Segment();
	Position& getSegment();
	virtual void draw();
	long getColor() const;
	void setColor(long c);
	virtual ~Segment();
};

#endif /* SEGMENT_H_ */
