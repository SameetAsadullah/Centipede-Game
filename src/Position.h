/*
 * Position.h
 *
 *  Created on: May 3, 2019
 *      Author: sameet_asadullah
 */

#ifndef POSITION_H_
#define POSITION_H_

class Position {
	int x,y;

public:
	Position();
	Position(int X, int Y);
	void setX(int X);
	int getX() const;
	void setY(int Y);
	int getY()const;
	virtual ~Position();
};

#endif /* POSITION_H_ */
