#ifdef __APPLE_CC__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "loadMap.h"
#include "drawMap.h"
#include "game.h"
#include "player.h"
#include "chooseMap.h"
#include "enemi.h"
#include "bullet.h"
#include "line.h"



int mX=90;
int mY=117;
int choose_map =0;

void initRendering()
{
	glEnable(GL_DEPTH_TEST);
}

void handleResize(int width,int heigth)
{
	glViewport(0, 0, width, heigth);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, width, heigth, 0);
}

void Display()
{
	
	glClearColor(0.0f,0.0f,0.0f,0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    game(mX, mY,p,e,t,lineL);//,
	glFlush();
}

int main(int argc, char *argv[])
{
	
	srand(time(NULL));
	loadMap(mX, mY);     //Charge la carte
	
	p=createPlayer(mX, mY);
	
	e = initialListEnemi();
    t = initialListeBullet();
	
	lineL=lodeLine(mX,  mY );
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);

	glutInitWindowSize((mY-2)*Square_size, mX*Square_size);

	glutCreateWindow("Test");

	initRendering();

	glutDisplayFunc(Display);
	glutReshapeFunc(handleResize);
	update();
	

	glutMainLoop();

	return 0;
}