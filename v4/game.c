#ifdef __APPLE_CC__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "loadMap.h"
#include "drawMap.h"
#include "game.h"
#include "chooseMap.h"
#include "bullet.h"
#include "enemi.h"
#include "line.h"


bool UP = false;
bool LEFT = false;
bool RIGHT = false;
bool DOWN = false;
bool SHOOT = false;

player p;

void Keyboard(unsigned char key, int x, int y)  // fonction allant gérer les input
{
	switch(key)
	{
		case 27:
			if (choose_map==0)
			{
				exit(0);
			}
			
			if (choose_map==1||choose_map==2)//if playing go to pause menu
			{
				choose_map=5;//pause
				loadMap(mX, mY);
			}
			if (choose_map==3||choose_map==4)//if exit setting or score back to accueil
			{
				choose_map=0;//accueil
				loadMap(mX, mY);
			}
		break;
				

		case'g':
			if (choose_map==0)
			{
				choose_map=1;//if accueil go to game
				loadMap(mX, mY);
				p=createPlayer(mX, mY);
				
			}						
		break;
		case'l':
			if (choose_map==0)
			{
				choose_map=2;//if accueil go to load
				loadMap(mX, mY);
				
				
			}						
		break;

			
		case's':
			if (choose_map==0)
			{
				choose_map=3;//score
				loadMap(mX, mY);
			}
			if (choose_map==1||choose_map==2)
			{
				DOWN = true;
			}
							
		break;

		case'c':
			if (choose_map==0)
			{
				choose_map=4;//commend
				loadMap(mX, mY);
			}
			
		break;
	
		case'z':
				if (choose_map==1||choose_map==2)
				{
				UP = true;
				
				}
		break;
		case'q':
			if (choose_map==1||choose_map==2)
				{
				LEFT = true;
				}
		break;
				

		case'd':
			if (choose_map==1||choose_map==2)
				{
				RIGHT = true;
				}
		break;	
	
		case ' ':
		if (choose_map==1||choose_map==2)
				{
				SHOOT = true;
				}
		break;	
	}
}



void game(int mX, int mY, player p,listeEnemiP e,listeBulletP t,listeLineP lineL)//
{


	drawWall(mX, mY);			//afficher la carte
	if (choose_map==1||choose_map==2)// draw player if playing new or saved game
	{
		drawPlayer(p);
	
		if (t->starList != NULL || t->endList != NULL)
		{
			drawAllBullet(t);	
		}	
		if (e->starList != NULL || e->endList != NULL)
		{
			drawAllEnnemi(e);	
		}
		if (lineL->starList != NULL || lineL->endList != NULL)
		{
			drawAllLine(lineL);	
		}
	}
	
	
	
	glutKeyboardFunc(Keyboard);		//fonction de glut gérant le clavier
	
	if (LEFT == true)
	{
		
		moveLeft(p);		//va se déplacer vers la gauche si on appuie sur q
		LEFT = false;
		
	}
	if (RIGHT == true)
	{
		
		moveRight(p);		//va se déplacer vers la droite si on apppuie sur d
		RIGHT = false;
	}
	if (UP == true)
	{
		moveUp(p);
		UP = false;
	}
	
	if (DOWN == true)
	{
		
        moveDown(p);
		DOWN = false;
	}

	if (SHOOT == true)
	{
		shoot(p, t);
		SHOOT=false;
	}
	glutPostRedisplay();
}