/*
 * Centipede.h
 *
 *  Created on: May 3, 2019
 *      Author: sameet_asadullah
 */

#ifndef CENTIPEDE_H_
#define CENTIPEDE_H_

#include"MoveableObject.h"
#include "util.h"
#include"MagicSeg.h"
#include"LazySeg.h"

class Centipede: public MoveableObject {
	bool leftCollision, rightCollision, upwardMotion;
	Segment** segments;
	int totalSegments;

public:
	Centipede(float X = 880, float Y = 720);
	void Draw();
	void Move();
	void MoveSegments();
	bool isLeftCollision() const;
	bool isRightCollision() const;
	void setLeftCollision(bool lc);
	void setRightCollision(bool rc);
	Segment**& getSegment();
	void setTotalSegments(int s);
	int getTotalSegments() const;
	void addMushrooms(GameObject** m, int &TotalMushrooms, int X, int Y);
	virtual ~Centipede();
};

#endif /* CENTIPEDE_H_ */
