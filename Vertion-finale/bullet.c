#ifdef __APPLE_CC__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "loadMap.h"
#include "player.h"
#include "bullet.h"
#include "bullet.h"
#include "chooseMap.h"
#include "game.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

bulletP r;
listeBulletP t;

//initielize the list of bullet
listeBulletP  initialListeBullet()
{
	listeBulletP t = malloc(sizeof(listeBullet));
	if (t == NULL)
	{
		exit(EXIT_FAILURE);
	}
	t->starList = NULL;
	t->endList = NULL;
	t->quantite = 0;
	return t;
}

//create a new bullet (when game is on and space is pressed)
bulletP createBullet(player p)
{
	int x = (p->pos.x);
	int y = ((p->pos.y)) + 1;
	bulletP new = malloc(sizeof(bullet));
	if (new == NULL)
	{
		exit(EXIT_FAILURE);
	}
	new->pos.x = x;
	new->pos.y = y;
	new->nextptr = NULL;
	new->prevptr = NULL;
	new->life = 1;
	return new;
}
// same as previous one but here take the data from the map tos set the pos and not the pos of the player
bulletP createBulletFromMap(int x,int y)
{		
	bulletP new = malloc(sizeof(bullet));
	if (new == NULL)
	{
		exit(EXIT_FAILURE);
	}
	new->life = 1;
	new->pos.x = x;
	new->pos.y = y;
	new->nextptr = NULL;
	new->prevptr = NULL;
	
	return new;
}

//insert a new bullet in the bullet chain
void insertionBullet(listeBulletP t, bulletP base)
{
	bulletP new = malloc(sizeof(bullet));
	if (new == NULL)
	{
		exit(EXIT_FAILURE);
	}
	new = base;
	if (t->starList == NULL || t->endList == NULL)
	{
		t->endList = new;
		t->starList = new;
	}
	else
	{
		new->nextptr = t->starList;
		t->starList->prevptr = new;
		t->starList = new;
	}
	t->quantite += 1;
}

//dleat  bullet from list if his life drop to 0 (if collision whith ennemi)
void suppressionBullet(listeBulletP t, int test)
{
	test = 0;
	if (t->starList != NULL)
	{
		bulletP base = malloc(sizeof(bullet));
		bulletP deleate = malloc(sizeof(bullet));
		base = t->starList;
		while (base != NULL)
		{
			if (base->life == test)
			{
				
				deleate = base;
				base = base->nextptr;
				if (t->starList == deleate && t->endList == deleate)
				{
					t->endList = NULL;
					t->starList = NULL;
				}
				else if (t->starList != deleate && t->endList == deleate)
				{
					t->endList = deleate->prevptr;
					t->endList->nextptr = NULL;
				}
				else if (t->starList == deleate && t->endList != deleate)
				{
					t->starList = deleate->nextptr;
					t->starList->prevptr = NULL;
				}
				else
				{
					deleate->nextptr->prevptr = deleate->prevptr;
					deleate->prevptr->nextptr = deleate->nextptr;
				}
				free(deleate);
				t->quantite--;
			}
			else
			{
				base = base->nextptr;
			}
		}
		free(base);	
		
	}
}

//deleat all the data from the list (make the list clean and new ^^)
void cleanListeBullet(listeBulletP b)
{
	bulletP base = b->starList;
	if (b->starList!=NULL)
	{	
 	  	while(base->nextptr!= NULL)
    	{
     	base=base->nextptr;
		base->prevptr=NULL;
		b->starList->nextptr=NULL;
		free(b->starList);
		b->starList=base;
		b->quantite--;
		}
	
	b->endList = NULL;
	b->starList = NULL;
}
}

//load ennemi from data on the map
listeBulletP lodeBullet(int mX, int mY )			// fonction qui cree le's enemis en fct de la carte
{   
	    
	if (choose_map==6)
    {        
	    for (int j = 0; j < mX; ++j)
	    {
		    for (int i = 0; i < mY; ++i)
		    {					   	
                if (*(*(map + j) + i)=='6')            
                { 
                    bulletP new = createBulletFromMap(j,i);
	                insertionBullet(t, new);                    
                }              
            }
        }//printf("%d",lineL->quantite);
    }
return t;
  
}  

// if space bar is pressed when game is on generate a new bullet and add it to the bullet list (only one wepon available for now)
void shoot(player p, listeBulletP t)
{
	
	if (weapon ==1&&bullettype1>0)
	{
		bulletP new = createBullet(p);
		insertionBullet(t, new);
		bullettype1--;
	}
	if (weapon ==2 && bullettype2>0)
	{
		//insertion du 2eme type de tirs
		bullettype2--;
	}
}