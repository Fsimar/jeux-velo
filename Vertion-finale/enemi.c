#ifdef __APPLE_CC__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "loadMap.h"
#include "enemi.h"
#include "player.h"
#include "chooseMap.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

enemiP q;
listeEnemiP e;

//initielize the list of ennemi
listeEnemiP initialListEnemi()
{
	listeEnemiP e = malloc(sizeof(struct listeEnemi));
	if (e == NULL)
	{
		exit(EXIT_FAILURE);
	}
	e->starList = NULL;
	e->endList = NULL;
	e->quantite = 0;
	return e;
}

//create a new ennemi
enemiP createEnemi(int *maxY)
{
	enemiP new = malloc(sizeof(enemi));
	int y = (rand() % (*maxY + 8) + 7);
	//                         lim droiet)+ lime gauche
	
	while (y==57) //si y= 57 (meme que la ligne centrale) prendre un autre random jusqu a avoir autrechose que 57
	{
		y = (rand() % (*maxY + 8) + 7);
	}
	
	if (new == NULL)
	{
		exit(EXIT_FAILURE);
	} 
	new->life = 1;
	new->pos.x = 5;
	new->pos.y = y;
	new->nextptr = NULL;
	new->prevptr = NULL;
	new->hit_point = 100;
	
	return new;
}

// create an ennemi depending of his position on the loded map
enemiP createEnemiFromMap(int x,int y)
{	
	enemiP new = malloc(sizeof(enemi));
	if (new == NULL)
	{
		exit(EXIT_FAILURE);
	}
	new->life = 1;
	new->pos.x = x;
	new->pos.y = y;
	new->nextptr = NULL;
	new->prevptr = NULL;
	new->hit_point = 100;
	return new;
}

//insert a new ennemi in the enemi chain
void insertionEnemi(listeEnemiP e, enemiP base)
{
	enemiP new = malloc(sizeof(enemi));
	if (new == NULL)
	{
		exit(EXIT_FAILURE);
	}
	new = base;
	if (e->starList == NULL || e->endList == NULL)
	{
		e->endList= new;
		e->starList = new;
	}
	else
	{
		new->nextptr = e->starList;
		e->starList->prevptr = new;
		e->starList = new;
	}
	e->quantite += 1;
}

//dleat ennei from list if his life drop to 0
void suppressionEnemi(listeEnemiP e, int test)
{	
	if (e->starList != NULL)
	{
		enemiP base = malloc(sizeof(enemi));
		enemiP deleate = malloc(sizeof(enemi));
		if (base == NULL)
		{
			exit(EXIT_FAILURE);
		}
		base = e->starList;
		while (base != NULL)
		{			
			if (base->life == 0)
			{				
				
				deleate = base;
				base = base->nextptr;
				if (e->starList == deleate && e->endList == deleate)
				{
					e->starList = NULL;
					e->endList = NULL;
				}
				else if (e->starList != deleate && e->endList == deleate)
				{
					e->endList = deleate->prevptr;
					e->endList->nextptr = NULL;
				}
				else if (e->starList == deleate && e->endList != deleate)
				{
					e->starList  = deleate->nextptr;
					e->starList->prevptr = NULL;
				}
				else
				{
					deleate->nextptr->prevptr = deleate->prevptr;
					deleate->prevptr->nextptr = deleate->nextptr;
				}
				free(deleate);
				e->quantite--;
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
void cleanListeEnnemi(listeEnemiP e)
{
	enemiP base = e->starList;
	if (e->starList!=NULL)
	{	
 	  	while(base->nextptr!= NULL)
    {
     	base=base->nextptr;
		base->prevptr=NULL;
		e->starList->nextptr=NULL;
		free(e->starList);
		e->starList=base;
		e->quantite--;
	}	
	e->endList = NULL;
	e->starList = NULL;
}
}

//load ennemi from data on the map
listeEnemiP lodeEnemi(int mX, int mY )			// fonction qui cree le's enemis en fct de la carte
{       
	if (choose_map==6)
    {        
	    for (int j = 0; j < mX; ++j)
	    {
		    for (int i = 0; i < mY; ++i)
		    {					   	
                if (*(*(map + j) + i)=='3')            
                { 
                    enemiP new = createEnemiFromMap(j,i);
	                insertionEnemi(e, new);                    
                }              
            }
        }
    }
	return e;  
}  
