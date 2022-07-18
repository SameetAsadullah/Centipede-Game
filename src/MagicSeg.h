/*
 * MagicSeg.h
 *
 *  Created on: May 4, 2019
 *      Author: sameet_asadullah
 */

#ifndef MAGICSEG_H_
#define MAGICSEG_H_

#include"Segment.h"
#include"util.h"

class MagicSeg:public Segment {
	int count;
public:
	MagicSeg();
	virtual void draw();
	virtual ~MagicSeg();
};

#endif /* MAGICSEG_H_ */
