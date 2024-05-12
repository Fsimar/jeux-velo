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
#include "update.h"
#include "save.h"



int mX=90;
int mY=117;
int choose_map =10;
bool pauseg = true;
bool gameover=false;
char* curentName;
int weapon =1;
int bullettype1=10;//nombre de mun pour la premiere arme
int bullettype2=5;//nombre de mun pour la 2e arme
int curentSaveLoded=0;
int LvL =0;
int baseEnemiSponeSpeed = 1000;//vitesse de spone des ennemis au niveau zero
int EnemiSponeSpeed=1000;

void initEnemiSponeSpeed()
{
	EnemiSponeSpeed=baseEnemiSponeSpeed; //vitesse courrante de spone
}

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

void Display()//call the game fct , game fct manage all the draw fct
{	
	glClearColor(0.0f,0.0f,0.0f,0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    game(mX, mY,p,e,t,lineL);	//manage all the game (interaction between the player and the game)  see game.c/.h
	glFlush();
}

int main(int argc, char *argv[])
{	
	srand(time(NULL));
	loadMap(mX, mY);     //Charge la carte
	loadBestScoreChart();		//load the Best Scors That are saved
	loadBestScoreNameChart();	//load the players names associated with the bests scors
	laodAllDataFromSave();		//load all the data related to the games saved (player name score...)
	initEnemiSponeSpeed();		//initialize the ennemi spne speed
	p=createPlayer(mX, mY);
	
	e = initialListEnemi(); 	//
    t = initialListeBullet();	//initialize the differents lists
	lineL=initialListeLine();	//
	
	glutInit(&argc, argv);
	glutInitWindowPosition(200, 200);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);

	glutInitWindowSize((mY-2)*Square_size, mX*Square_size);
	
	glutCreateWindow("Car-Killer");

	initRendering();

	glutDisplayFunc(Display);
	glutReshapeFunc(handleResize);
	
	update();					//manage all the updates from the game see update.c/.h
	
	glutMainLoop();

	return 0;
}