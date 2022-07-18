/*
 * Game.cpp
 *
 *  Created on: May 4, 2019
 *      Author: sameet_asadullah
 */

#include "Game.h"

Game::Game() :
		tMushrooms(25), count(0), drawMushroom(0), oldMushrooms(25), pauseGame(
				0), endGame(false), splittingOfCentipede(false), body(0), menuWorking(
				true) {
	ptr = new MoveableObject *[2];
	ptr[0] = new Player;
	ptr[1] = new Bullet;

	ptr1 = new GameObject *[100];
	for (int i = 0; i < 100; i++) {
		ptr1[i] = new Mushroom;
	}
}

void Game::CheckMushroom() {
	for (int i = 0; i < oldMushrooms; i++) {
		for (int j = 0; j < oldMushrooms; j++) {
			if (i != j) {
				if ((abs(ptr1[i]->getP().getX() - ptr1[j]->getP().getX()) < 15)
						|| (abs(ptr1[i]->getP().getY() - ptr1[j]->getP().getY())
								< 15)) {
					ptr1[i]->getP().setX(GetRandInRange(30, 980));
					ptr1[i]->getP().setY(GetRandInRange(70, 680));
					CheckMushroom();
				}
			}
		}
	}
}

void Game::DrawMushroom() {
	collisionWithBulletAndMushroom();
	CheckMushroom();
	for (int i = 0; i < tMushrooms; i++) {
		if (ptr1[i]->getP().getX() != 0 && ptr1[i]->getP().getY() != 0) {
			ptr1[i]->Draw();
		}
	}
}

void Game::collisionWithBulletAndMushroom() {
	for (int i = 0; i < tMushrooms; i++) {
		if ((ptr[1]->getP().getX() > (ptr1[i]->getP().getX() - 6))
				&& (ptr[1]->getP().getX() < (ptr1[i]->getP().getX() + 20))
				&& (abs(ptr1[i]->getP().getY() - ptr[1]->getP().getY()) <= 10)) {
			ptr1[i]->setLives(ptr1[i]->getLives() - 1);
			ptr[1]->getP().setY(800);
			if (ptr1[i]->getLives() == 0) {
				for (int j = i; j < tMushrooms; j++) {
					ptr1[j]->getP().setX(ptr1[j + 1]->getP().getX());
					ptr1[j]->getP().setY(ptr1[j + 1]->getP().getY());
					ptr1[j]->setLives(2);
				}
				sb.setScore(sb.getScore() + 5);
				oldMushrooms--;
				tMushrooms--;
			}
		}
	}
}

void Game::checkFlea() {
	collisionWithBulletAndFlea();

	for (int i = 0; i < oldMushrooms; i++) {
		if ((f.getP().getX() > (ptr1[i]->getP().getX() - 20))
				&& (f.getP().getX() < (ptr1[i]->getP().getX() + 20))) {
			f.getP().setX(GetRandInRange(40, 960));
			checkFlea();
		}
	}

	count++;
	if (count > 500 && (f.getP().getY() >= 0 || f.getP().getY() == -100)) {
		if (f.getP().getY() != -100) {
			f.Draw();
			if (tMushrooms <= 100) {
				if (f.getMoveCount() == 4) {
					drawMushroom = GetRandInRange(0, 3);
					if (drawMushroom == 1) {
						f.addMushroom(ptr1, tMushrooms);
						DrawMushroom();
					}
				}
			}

			f.Move();
		}

		if (f.getP().getY() <= 0) {
			count = 0;
			f.getP().setX(GetRandInRange(40, 960));
			f.getP().setY(740);
		}
	}

}

void Game::collisionWithBulletAndFlea() {
	if ((ptr[1]->getP().getX() > (f.getP().getX() - 15))
			&& (ptr[1]->getP().getX() < (f.getP().getX() + 15))
			&& (abs(ptr[1]->getP().getY() - f.getP().getY()) < 10)
			&& f.getP().getY() != -100) {
		ptr[1]->getP().setY(800);
		f.getP().setX(GetRandInRange(40, 960));
		f.getP().setY(740);
		count = 0;
		sb.setScore(sb.getScore() + 200);
	}
}

void Game::collisionWithMushroomAndCentipede() {
	for (int i = 0; i < tMushrooms; i++) {
		if ((abs(
				c.getSegment()[0]->getSegment().getX() - ptr1[i]->getP().getX())
				< 10)
				&& ((abs(
						c.getSegment()[0]->getSegment().getY()
								- ptr1[i]->getP().getY()) < 20))) {
			c.getSegment()[0]->getSegment().setY(
					c.getSegment()[0]->getSegment().getY() - 20);
			if (c.isLeftCollision()) {
				c.setLeftCollision(false);
				c.setRightCollision(true);
				c.getSegment()[0]->getSegment().setX(
						c.getSegment()[0]->getSegment().getX() - 20);
			}

			else if (c.isRightCollision()) {
				c.setRightCollision(false);
				c.setLeftCollision(true);
				c.getSegment()[0]->getSegment().setX(
						c.getSegment()[0]->getSegment().getX() + 20);
			}
		}

		if (splittingOfCentipede == true) {
			if ((abs(
					c1.getSegment()[0]->getSegment().getX()
							- ptr1[i]->getP().getX()) < 10)
					&& ((abs(
							c1.getSegment()[0]->getSegment().getY()
									- ptr1[i]->getP().getY()) < 20))) {
				c1.getSegment()[0]->getSegment().setY(
						c1.getSegment()[0]->getSegment().getY() - 20);
				if (c1.isLeftCollision()) {
					c1.setLeftCollision(false);
					c1.setRightCollision(true);
					c1.getSegment()[0]->getSegment().setX(
							c1.getSegment()[0]->getSegment().getX() - 20);
				}

				else if (c1.isRightCollision()) {
					c1.setRightCollision(false);
					c1.setLeftCollision(true);
					c1.getSegment()[0]->getSegment().setX(
							c1.getSegment()[0]->getSegment().getX() + 20);
				}
			}
		}
	}
}

void Game::collisionWithFleaAndPlayer() {
	if ((f.getP().getX() > (ptr[0]->getP().getX() - 10))
			&& (f.getP().getX() < (ptr[0]->getP().getX() + 60))
			&& (f.getP().getY() < (ptr[0]->getP().getY() + 30))
			&& f.getP().getY() > 0) {
		f.getP().setY(-100);
		ptr[0]->setLives(ptr[0]->getLives() - 1);
		pauseGame++;

		if (ptr[0]->getLives() == 0) {
			endGame = true;
		}
	}

	if (pauseGame != 0 && !endGame) {
		pauseGame++;
		DrawString(450, 600, "uh oh Lives--", colors[WHITE]);
	}
}

void Game::collisionWithCentipedeAndPlayer() {
	if ((c.getSegment()[0]->getSegment().getX() > (ptr[0]->getP().getX() - 10))
			&& (c.getSegment()[0]->getSegment().getX()
					< (ptr[0]->getP().getX() + 60))
			&& (c.getSegment()[0]->getSegment().getY()
					< (ptr[0]->getP().getY() + 30))
			&& (c.getSegment()[0]->getSegment().getY()
					> (ptr[0]->getP().getY() - 10))) {
		ptr[0]->setLives(ptr[0]->getLives() - 1);
		c.getSegment()[0]->getSegment().setX(880);
		c.getSegment()[0]->getSegment().setY(720);
		c.setRightCollision(false);
		c.setLeftCollision(false);
		pauseGame++;
		splittingOfCentipede = false;
		for (int i = 1; i < 7; i++) {
			c.getSegment()[i]->getSegment().setX(0);
		}

		if (ptr[0]->getLives() == 0) {
			endGame = true;
		}
	}

	if (splittingOfCentipede == true) {
		if ((c1.getSegment()[0]->getSegment().getX()
				> (ptr[0]->getP().getX() - 10))
				&& (c1.getSegment()[0]->getSegment().getX()
						< (ptr[0]->getP().getX() + 60))
				&& (c1.getSegment()[0]->getSegment().getY()
						< (ptr[0]->getP().getY() + 30))
				&& (c1.getSegment()[0]->getSegment().getY()
						> (ptr[0]->getP().getY() - 10))) {
			ptr[0]->setLives(ptr[0]->getLives() - 1);
			c.getSegment()[0]->getSegment().setX(880);
			c.getSegment()[0]->getSegment().setY(720);
			c.setRightCollision(false);
			c.setLeftCollision(false);
			c1.setRightCollision(false);
			c1.setLeftCollision(false);
			splittingOfCentipede = false;
			pauseGame++;

			for (int i = 1; i < 7; i++) {
				c.getSegment()[i]->getSegment().setX(0);
			}

			if (ptr[0]->getLives() == 0) {
				endGame = true;
			}
		}
	}
}

void Game::splitting() {
	for (int i = 1; i < 6; i++) {
		if (i >= 2) {
			if ((abs(
					ptr[1]->getP().getX()
							- c.getSegment()[i]->getSegment().getX()) <= 10)
					&& (abs(
							ptr[1]->getP().getY()
									- c.getSegment()[i]->getSegment().getY())
							<= 10)) {
				ptr[1]->getP().setY(800);
				for (int j = i; j < 7; j++) {
					c.getSegment()[j]->getSegment().setX(-100);
					c.getSegment()[j]->getSegment().setY(-100);
				}

				body = 7 - i - 1;

				c1.getSegment() = new Segment *[body];
				c1.getSegment()[0] = new MagicSeg;

				c1.setTotalSegments(body);

				for (int j = 1; j < body; j++) {
					c1.getSegment()[j] = new LazySeg;
				}

				c1.getSegment()[0]->getSegment().setY(
						c.getSegment()[0]->getSegment().getY() - 20);

				splittingOfCentipede = true;

				if (c.isRightCollision()) {
					c1.getSegment()[0]->getSegment().setX(
							c.getSegment()[0]->getSegment().getX() + 30);
					c1.setLeftCollision(true);

				}

				if (c.isLeftCollision()) {
					c1.getSegment()[0]->getSegment().setX(
							c.getSegment()[0]->getSegment().getX() - 30);
					c1.setRightCollision(true);
				}
			}
		}
	}
}

void Game::collisionWithCentipedeAndBullet() {
	for (int i = 1; i < 7; i++) {
		if ((abs(ptr[1]->getP().getX() - c.getSegment()[i]->getSegment().getX())
				<= 10)
				&& (abs(
						ptr[1]->getP().getY()
								- c.getSegment()[i]->getSegment().getY()) <= 10)) {

			c.addMushrooms(ptr1, tMushrooms,
					c.getSegment()[i]->getSegment().getX(),
					c.getSegment()[i]->getSegment().getY());

			c.getSegment()[i]->getSegment().setX(-100);
			c.getSegment()[i]->getSegment().setY(-100);
			ptr[1]->getP().setY(800);
		}
	}

	for (int i = 1; i < body; i++) {
		if ((abs(
				ptr[1]->getP().getX() - c1.getSegment()[i]->getSegment().getX())
				<= 10)
				&& (abs(
						ptr[1]->getP().getY()
								- c1.getSegment()[i]->getSegment().getY()) <= 10)) {

			c1.addMushrooms(ptr1, tMushrooms,
					c1.getSegment()[i]->getSegment().getX(),
					c1.getSegment()[i]->getSegment().getY());

			c1.getSegment()[i]->getSegment().setX(-100);
			c1.getSegment()[i]->getSegment().setY(-100);
			ptr[1]->getP().setY(800);
		}
	}
}

Game::~Game() {
}

