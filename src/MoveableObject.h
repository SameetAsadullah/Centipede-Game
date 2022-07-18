/*
 * MoveableObject.h
 *
 *  Created on: May 3, 2019
 *      Author: sameet_asadullah
 */

#ifndef MOVEABLEOBJECT_H_
#define MOVEABLEOBJECT_H_

#include"GameObject.h"
#include<string>
using namespace std;

class MoveableObject:public GameObject{
public:
	MoveableObject();
	MoveableObject(float X, float Y);
	virtual void Move() = 0;
	virtual ~MoveableObject();
};

#endif /* MOVEABLEOBJECT_H_ */
