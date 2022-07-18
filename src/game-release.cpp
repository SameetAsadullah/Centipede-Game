//============================================================================
// Name        : .cpp
// Author      : Sibt ul Hussain
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game of Centipede...
//============================================================================

#ifndef CENTIPEDE_CPP_
#define CENTIPEDE_CPP_
#include "Board.h"
#include "util.h"
#include <iostream>
#include<string>
#include<cmath> // for basic math functions such as cos, sin, sqrt
#include"Centipede.h"
#include"Game.h"
#include"Mushroom.h"
using namespace std;
Game g;
// seed the random numbers generator by current time (see the documentation of srand for further help)...

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
void SetCanvasSize(int width, int height) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

/*
 * Main Canvas drawing function.
 * */
Board *b;
void GameDisplay()/**/{
	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

	glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0/*Blue Component*/, 1 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear(GL_COLOR_BUFFER_BIT); //Update the colors
	//Fire Gun
	//DrawSquare( 400 , 20 ,40,colors[RED]);
	//Mushroom
	//DrawSquare( 250 , 250 ,20,colors[GREEN]);
	//Display Score
	/*DrawString(50, 800, "Score = ", colors[WHITE]);
	 DrawString(130, 800, to_string(g.sb.getScore()), colors[WHITE]);*/
	if (g.menuWorking) {
		g.sb.drawMenu();
	}

	if (g.sb.getMenu() == 1) {
		g.menuWorking = false;
		DrawString(50, 760, "Lives = ", colors[WHITE]);
		DrawString(130, 760, to_string(g.ptr[0]->getLives()), colors[WHITE]);
		//Spider
		//DrawTriangle( 300, 450 , 340, 450 , 320 , 490, colors[MISTY_ROSE] );
		// Trianlge Vertices v1(300,50) , v2(500,50) , v3(400,250)

		//DrawLine(int x1, int y1, int x2, int y2, int lwidth, float *color)

		if (!g.endGame && (g.pauseGame == 0 || g.pauseGame == 100)) {
			if (g.pauseGame == 100) {
				g.pauseGame = 0;
			}

			g.c.Draw();
			g.c.Move();
			if (g.splittingOfCentipede) {
				g.c1.Draw();
				g.c1.Move();
				g.collisionWithCentipedeAndBullet();
			}

			if (g.splittingOfCentipede == false) {
				g.splitting();
			}

			g.collisionWithMushroomAndCentipede();
			g.ptr[0]->Draw();
			g.ptr[1]->Draw();
			g.ptr[1]->Move();
			g.checkFlea();
			g.DrawMushroom();
		}
		g.collisionWithFleaAndPlayer();
		g.collisionWithCentipedeAndPlayer();
		g.sb.Draw();
		g.sb.checkAndUpdateHighScore();
		if (g.endGame) {
			DrawString(450, 470, "Game Over", colors[WHITE]);
		}
	}

	if (g.sb.getMenu() == 2) {
		g.sb.drawMenu();
		g.sb.checkAndUpdateHighScore();
		DrawString(543, 447, " = ", colors[WHITE]);
		DrawString(572, 447, to_string(g.sb.getHighScore()), colors[WHITE]);
	}

	if (g.sb.getMenu() == 3) {
		exit(1);
	}

	glutSwapBuffers(); // do not modify this line..

}

/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */

void NonPrintableKeys(int key, int x, int y) {
	if (g.ptr[0]->getP().getX() > 15) {
		if (key == GLUT_KEY_LEFT) {
			g.ptr[0]->getP().setX(g.ptr[0]->getP().getX() - 20);
		}
	}

	if (g.ptr[0]->getP().getX() < 955) {
		if (key == GLUT_KEY_RIGHT) {
			g.ptr[0]->getP().setX(g.ptr[0]->getP().getX() + 20);
		}
	}

	if (g.ptr[0]->getP().getY() < 100) {
		if (key == GLUT_KEY_UP) {
			g.ptr[0]->getP().setY(g.ptr[0]->getP().getY() + 20);
		}
	}

	if (g.ptr[0]->getP().getY() > 20) {
		if (key == GLUT_KEY_DOWN) {
			g.ptr[0]->getP().setY(g.ptr[0]->getP().getY() - 20);
		}
	}

	if (g.menuWorking == true) {
		g.sb.setDirection(key);
	}
	key = 0;

	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/

	//glutPostRedisplay();
}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
void PrintableKeys(unsigned char key, int x, int y) {
	if (key == 27/* Escape key ASCII*/) {
		exit(1); // exit the program when escape key is pressed.
	}

	if (key == 'b' || key == 'B') //Key for placing the bomb
			{
		//do something if b is pressed
		cout << "b pressed" << endl;

	}

	if (key == 32) {
		if (g.ptr[1]->getP().getY() == 0 || g.ptr[1]->getP().getY() >= 740) {
			g.ptr[1]->getP().setX(g.ptr[0]->getP().getX() + 25);
			g.ptr[1]->getP().setY(g.ptr[0]->getP().getY() + 40);
		}
	}

	//glutPostRedisplay();
}

/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */
void Timer(int m) {

	// implement your functionality here
	GameDisplay();
	// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(15, Timer, 0);
}

/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */
void MousePressedAndMoved(int x, int y) {
	cout << x << " " << y << endl;
	//glutPostRedisplay();
}
void MouseMoved(int x, int y) {

	//glutPostRedisplay();
}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */
void MouseClicked(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
	{
		cout << GLUT_DOWN << " " << GLUT_UP << endl;

	} else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
	{

	}
	//glutPostRedisplay();
}
/*
 * our gateway main function
 * */
int main(int argc, char*argv[]) {

	b = new Board(60, 60); // create a new board object to use in the Display Function ...
	int width = 1020, height = 840; // i have set my window size to be 800 x 600
	b->InitalizeBoard(width, height);
	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("OOP Centipede"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.

	glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1000.0, Timer, 0);

	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	return 1;
}
#endif /* AsteroidS_CPP_ */
