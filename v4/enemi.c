#ifdef __APPLE_CC__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "loadMap.h"
#include "enemi.h"
#include "player.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

enemiP q;
listeEnemiP e;
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

enemiP createEnemi(int *maxY)
{
	enemiP new = malloc(sizeof(enemi));
	int y = (rand() % (*maxY + 10) + 10);
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

void suppressionEnemi(listeEnemiP e, int test)
{
	test = 0;
	if (e->starList != NULL)
	{
		enemiP base = malloc(sizeof(enemi));
		if (base == NULL)
		{
			exit(EXIT_FAILURE);
		}
		base = e->starList;
		while (base != NULL)
		{
			if (base->life == test)
			{
				enemiP deleate = malloc(sizeof(enemi));
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
	}
}
