#ifdef __APPLE_CC__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "loadMap.h"
#include "player.h"
#include "bullet.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

bulletP r;
listeBulletP t;

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

void suppressionBullet(listeBulletP t, int test)
{
	test = 0;
	if (t->starList != NULL)
	{
		bulletP base = malloc(sizeof(bullet));
		base = t->starList;
		while (base != NULL)
		{
			if (base->life == test)
			{
				bulletP deleate = malloc(sizeof(bullet));
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
	}
}




void shoot(player p, listeBulletP t)
{
	bulletP new = createBullet(p);
	insertionBullet(t, new);
}