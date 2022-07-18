/*
 * ScoreBoard.cpp
 *
 *  Created on: May 8, 2019
 *      Author: sameet_asadullah
 */

#include "ScoreBoard.h"

ScoreBoard::ScoreBoard() :
		score(0), highScore(0), y(470), menu(0), direction (0), menuWorking(true) {
}

void ScoreBoard::Draw() {
	DrawString(50, 800, "Score = ", colors[WHITE]);
	DrawString(130, 800, to_string(score), colors[WHITE]);
	DrawString(800, 800, "High Score = ", colors[WHITE]);
	DrawString(940, 800, to_string(highScore), colors[WHITE]);

	DrawLine(0, 740, 1020, 740, 5, colors[WHITE]);
	DrawLine(0, 0, 0, 840, 10, colors[WHITE]);
	DrawLine(0, 0, 1020, 0, 10, colors[WHITE]);
	DrawLine(1020, 0, 1020, 840, 10, colors[WHITE]);
	DrawLine(0, 840, 1020, 840, 10, colors[WHITE]);
	DrawLine(0, 140, 1020, 140, 5, colors[WHITE]);
}

void ScoreBoard::setScore(int S) {
	score = S;
}

int ScoreBoard::getScore() const {
	return score;
}

void ScoreBoard::checkAndUpdateHighScore() {
	fstream input;
	input.open("scr.txt", ios::in);
	input >> highScore;
	if (highScore < score) {
		fstream output;
		output.open("scr.txt", ios::out);
		output << score;
		output.close();
	}
	input.close();
}

void ScoreBoard::drawMenu() {
	DrawLine(0, 0, 0, 840, 10, colors[WHITE]);
	DrawLine(0, 0, 1020, 0, 10, colors[WHITE]);
	DrawLine(1020, 0, 1020, 840, 10, colors[WHITE]);
	DrawLine(0, 840, 1020, 840, 10, colors[WHITE]);
	DrawRoundRect(415, y, 210, 32, colors[BLUE], 8);

	DrawString(430, 477, "Start New Game", colors[WHITE]);
	DrawString(430, 447, "High Score", colors[WHITE]);
	DrawString(430, 417, "Exit", colors[WHITE]);

	if (direction == GLUT_KEY_DOWN && y>410) {
		y -= 30;
		direction = 0;
	}

	if (direction == GLUT_KEY_UP && y<470) {
		y += 30;
		direction = 0;
	}

	if (direction == GLUT_KEY_RIGHT /*|| direction == 13*/) {
		if (y==470) {
			menu = 1;
		}

		else if (y==440) {
			menu = 2;
		}

		else if (y == 410) {
			menu = 3;
		}
	}
}

void ScoreBoard::setMenu(int m) {
	menu = m;
}

int ScoreBoard::getMenu() const {
	return menu;
}

void ScoreBoard::setDirection(int d) {
	direction = d;
}

int ScoreBoard::getDirection() const {
	return direction;
}

int ScoreBoard::getHighScore() const {
	return highScore;
}

ScoreBoard::~ScoreBoard() {
}
