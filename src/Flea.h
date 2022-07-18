/*
 * Flea.h
 *
 *  Created on: May 5, 2019
 *      Author: sameet_asadullah
 */

#ifndef FLEA_H_
#define FLEA_H_

#include"MoveableObject.h"
#include"Mushroom.h"

class Flea: public MoveableObject {
	int moveCount;

public:
	Flea();
	void Draw();
	void Move();
	void setMushrooms();
	void DrawMushrooms();
	void addMushroom(GameObject** m, int &TotalMushrooms);
	int getMoveCount() const;
	virtual ~Flea();
};

#endif /* FLEA_H_ */
