#ifdef __APPLE_CC__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "loadMap.h"
#include "player.h"
#include "game.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//create a player struct with standart stat(life ammo...)
player createPlayer(int mX, int mY)
{
	player p;
	int x = 0, y = 0;

	for (int i = 0; i < mX; ++i)
	{
		for (int j = 0; j < mY; ++j)
		{
			if(*(*(map + i) + j) == '4')
			{
				x = i;
				y = j;
			}
		}
	}
	p = malloc(sizeof(player));
	p->life = 3;
	p->hit_point=100;
	p->pos.x = x;
	p->pos.y = y;
	p->score = 0;
	p->speed=20;
	
	return p;
}

//la fonction va vérifier si on peut se déplacer vers la gauche et le faire le cas échéant
void moveLeft(player p)		
{
	if (*(*(map + p->pos.x) + (p->pos.y-1)) !='2')
	{
	p->pos.y-=1 ;
	}
}

//la fonction va vérifier si on peut se déplacer vers la droite et le faire le cas échéant
void moveRight(player p)		
{
   if (*(*(map + p->pos.x) + (p->pos.y+4)) !='2')
	{
	p->pos.y+=1;
	}
}



void moveUp(player p)
{
	if (p->pos.x-1 >50)
	{
		p->pos.x-=1;
	}  
}

void moveDown(player p)
{
   if (p->pos.x-1 <84)
    {
	p->pos.x +=1;
    }
}

