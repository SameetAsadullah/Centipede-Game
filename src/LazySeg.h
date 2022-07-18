/*
 * LazySeg.h
 *
 *  Created on: May 4, 2019
 *      Author: sameet_asadullah
 */

#ifndef LAZYSEG_H_
#define LAZYSEG_H_

#include"Segment.h"
#include"util.h"

class LazySeg:public Segment {
public:
	LazySeg();
	virtual void draw();
	virtual ~LazySeg();
};

#endif /* LAZYSEG_H_ */
