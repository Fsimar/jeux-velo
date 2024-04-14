#ifdef __APPLE_CC__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "loadMap.h"
#include "player.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>





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

	return p;
}

void moveLeft(player p)		//la fonction va vérifier si on peut se déplacer vers la gauche et le faire le cas échéant
{
	
     
	if (*(*(map + p->pos.x) + (p->pos.y-1)) !='0')
	{
	p->pos.y-=1 ;
	}

}

void moveRight(player p)		//la fonction va vérifier si on peut se déplacer vers la droite et le faire le cas échéant
{


   if (*(*(map + p->pos.x) + (p->pos.y+4)) !='0')
	{
	p->pos.y+=1;
	}
	
}



void moveUp(player p)
{


if (p->pos.x-1 >15)
 {
	p->pos.x-=1;
  }     

}

void moveDown(player p)
{

   
   if (*(*(map + (p->pos.x+3)) + p->pos.y) !='6')
    {
	p->pos.x +=1;
    }
}
