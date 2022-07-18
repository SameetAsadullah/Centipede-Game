/*
 * ScoreBoard.h
 *
 *  Created on: May 8, 2019
 *      Author: sameet_asadullah
 */

#ifndef SCOREBOARD_H_
#define SCOREBOARD_H_
#include "GameObject.h"
#include<fstream>
using namespace std;

class ScoreBoard: public GameObject {
	int score, highScore, y, menu, direction;
	bool menuWorking;

public:
	ScoreBoard();
	void setScore(int S);
	int getScore() const;
	void Draw();
	void checkAndUpdateHighScore();
	void drawMenu();
	void setMenu(int m);
	int getMenu() const;
	void setDirection(int d);
	int getDirection() const;
	int getHighScore() const;
	virtual ~ScoreBoard();
};

#endif /* SCOREBOARD_H_ */
