/*
 * GameObject.cpp
 *
 *  Created on: May 3, 2019
 *      Author: sameet_asadullah
 */

#include "GameObject.h"

GameObject::GameObject():lives(0) {
}

GameObject::GameObject(int X, int Y):lives(0) {
	p.setX(X);
	p.setY(Y);
}

Position& GameObject::getP(){
	return p;
}

void GameObject::setLives(int l) {
	if (l>=0) {
		lives = l;
	}
}

int GameObject::getLives() const {
	return lives;
}

GameObject::~GameObject() {
}

