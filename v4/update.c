#ifdef __APPLE_CC__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "loadMap.h"
#include "player.h"
#include "bullet.h"
#include "enemi.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include "enemi.h"
#include "update.h"
#include "line.h"
int test=0;


void updateLine(int valeur)
{
	linept = lineL->starList;
	if (lineL->starList != NULL)
	{
		linept->pos.x += 1;
		if (linept->pos.x > 89)
		{
			linept->pos.x = 2;
			
		}
		while (linept->nextptr != NULL)
		{
			linept = linept->nextptr;
			linept->pos.x += 1;
			if (linept->pos.x >89)
			{
				linept->pos.x = 2;
				
			}
		}
	}
	glutPostRedisplay();
	glutTimerFunc(300, updateLine, 2);
}

void updateBullet(int valeur)
{
	r = t->starList;
	if (t->starList != NULL)
	{
		r->pos.x -= 1;
		if (r->pos.x < 1)
		{
			r->pos.x = 88;
			r->life = 0;
		}
		while (r->nextptr != NULL)
		{
			r = r->nextptr;
			r->pos.x -= 1;
			if (r->pos.x < 1)
			{
				r->pos.x = 88;
				r->life = 0;
			}
		}
	}
	glutPostRedisplay();
	glutTimerFunc(50, updateBullet, 2);
}

void updateDeleteBullet(int valeur)
{
	if (t->starList != NULL || t->endList != NULL)
	{
		suppressionBullet(t, test);
	}
	glutPostRedisplay();
	glutTimerFunc(50, updateDeleteBullet, 5);
}

void updateEnemi(int valeur)
{
	q = e->starList;
	if (e->starList != NULL)
	{
		q->pos.x += 1;
		if (q->pos.x > 89)
		{
			q->pos.x = 2;
			q->life = 0;
		}
		while (q->nextptr != NULL)
		{
			q = q->nextptr;
			q->pos.x +=1;
			if (q->pos.x > 89)
			{
				q->pos.x = 2;
				q->life = 0;
			}
		}
	}
	glutPostRedisplay();
	glutTimerFunc(200, updateEnemi, 1);
}

void updateNewEnemi(int valeur)
{
	enemiP new = createEnemi((&mX));
	insertionEnemi(e, new);
	glutPostRedisplay();
	glutTimerFunc(1000, updateNewEnemi, 3);
}


void updateDeleateEnemi(int valeur)
{
	if (e->starList != NULL || e->endList != NULL)
	{
		suppressionEnemi(e, test);
	}
	glutPostRedisplay();
	glutTimerFunc(200, updateDeleateEnemi, 4);
}


void update(){

    //glutTimerFunc(50, updateCollisions, 0);
	glutTimerFunc(10, updateEnemi, 1);
	glutTimerFunc(300, updateLine, 2);
	glutTimerFunc(50, updateBullet, 2);
	glutTimerFunc(30, updateNewEnemi, 3);
	glutTimerFunc(20, updateDeleateEnemi, 4);
	glutTimerFunc(50, updateDeleteBullet, 5);  
}