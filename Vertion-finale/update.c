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
#include "enemi.h"
#include "update.h"
#include "line.h"
#include "collision.h"
#include "chooseMap.h"
#include "game.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

int test=0;


void updateLine(int valeur)
{
	if ((choose_map==1||choose_map==6 )&& pauseg==false)//n uniquement si map de jeux et pas de pause
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
	}
	
	glutTimerFunc(300, updateLine, 2);	
}

void updateBullet(int valeur)
{
	if ((choose_map==1||choose_map==6)&& pauseg==0)//n uniquement si map de jeux et pas de pause
	{
	r = t->starList;
	if (t->starList != NULL)
	{
			r->pos.x -= 1;
			if (r->pos.x < 1)
			{
				r->pos.x = 90;
				r->life = 0;
			}
			while (r->nextptr != NULL)
			{
				r = r->nextptr;
				r->pos.x -= 1;
				if (r->pos.x < 1)
				{
					r->pos.x = 90;
					r->life = 0;
				}
			}
		}
	glutPostRedisplay();
	}
	
	glutTimerFunc(50, updateBullet, 2);	
}

void updateDeleteBullet(int valeur)
{
	if ((choose_map==1||choose_map==6)&& pauseg==0)//n uniquement si map de jeux et pas de pause
	{
		if (t->starList != NULL || t->endList != NULL)
		{
			suppressionBullet(t, test);
		}
	glutPostRedisplay();
	}
	
	glutTimerFunc(50, updateDeleteBullet, 5);
}

void updateEnemi(int valeur)
{ 
	if ((choose_map==1||choose_map==6) && pauseg==0)//n uniquement si map de jeux et pas de pause
	{
		q = e->starList;
		if (e->starList != NULL)
		{
			q->pos.x += 1;
			if (q->pos.x > 89)
			{
				q->pos.x = 2;
				q->life = 0;
				p->life--;
			}
			while (q->nextptr != NULL)
			{
				q = q->nextptr;
				q->pos.x +=1;
				if (q->pos.x > 89)
				{
					q->pos.x = 2;
					q->life = 0;
					p->life--;
				}
			}
		}		
	glutPostRedisplay();
	}

	glutTimerFunc(200, updateEnemi, 1);
}

void updateNewEnemi(int valeur)
{
	if ((choose_map==1||choose_map==6) && pauseg==0)//n uniquement si map de jeux et pas de pause
	{
		enemiP new = createEnemi((&mX));
		insertionEnemi(e, new);
		glutPostRedisplay();
	}

	glutTimerFunc(EnemiSponeSpeed, updateNewEnemi, 3);
}


void updateDeleateEnemi(int valeur)
{
	if ((choose_map==1||choose_map==6) && pauseg==0)//n uniquement si map de jeux et pas de pause
	{
		if (e->starList != NULL || e->endList != NULL)
		{
			suppressionEnemi(e, test);
		}
		glutPostRedisplay();
	}	
	glutTimerFunc(200, updateDeleateEnemi, 4);
}


void updateCollisionEnemiBullet(int valeur)
{
	if ((choose_map==1||choose_map==6) && pauseg==0)//n uniquement si map de jeux et pas de pause
	{
		enemiP baseE = e->starList;
		bulletP baseP = t->starList;
		if (e->starList != NULL && t->starList != NULL)
		{
			CollisionEnemiBullet(baseE, baseP);// test les deux start liste ensemble
			
			while (baseP->nextptr != NULL)// chec collision entre bullettes et 1er enemi (dernier enemi ajouté)
				{
					baseP = baseP->nextptr;
					CollisionEnemiBullet(baseE, baseP);
					
				}
				
			
			while (baseE->nextptr != NULL)//(chec col entre tout les enemis (sauf dernier ajouté)et tt bullets sauf dernier ajouté)
			{
				baseP = t->starList;
				baseE = baseE->nextptr;
				CollisionEnemiBullet(baseE, baseP);
				while (baseP->nextptr != NULL)
				{
					baseP = baseP->nextptr;
					CollisionEnemiBullet(baseE, baseP);
					
				}			
			}
		}
		glutPostRedisplay();
	}		
	glutTimerFunc(50, updateCollisionEnemiBullet, 0);
}


void updateCollisionEnemiPlayer(int valeur)
{
	if ((choose_map==1||choose_map==6) && pauseg==0)//n uniquement si map de jeux et pas de pause
	{
		enemiP baseE = e->starList;
		if (e->starList != NULL )
		{
			CollisionEnemiPlayer(baseE);
			
			while (baseE->nextptr != NULL)// chec collision entre bullettes et 1er enemi (dernier enemi ajouté)
			{
				baseE = baseE->nextptr;
				CollisionEnemiPlayer(baseE);					
			}			
		}
		glutPostRedisplay();
	}	
	glutTimerFunc(50, updateCollisionEnemiPlayer, 0);
}

void moveplayer(int valeur)
{
	if ((choose_map==1||choose_map==6) && pauseg==0)// uniquement si map de jeux et pas de pause
	{
		if (LEFT == true)
		{			
			moveLeft(p);		//va se déplacer vers la gauche si on appuie sur q
			//LEFT = false;
			
		}
		if (RIGHT == true)
		{			
			moveRight(p);		//va se déplacer vers la droite si on apppuie sur d
			//RIGHT = false;
		}
		if (UP == true)
		{
			moveUp(p);
			//UP = false;
		}
		
		if (DOWN == true)
		{			
			moveDown(p);
			//DOWN = false;
		}

		if (SHOOT == true)
		{
			shoot(p, t);
			SHOOT=false;
		}
		glutPostRedisplay();
	}
	glutTimerFunc(p->speed, moveplayer, 0);
}

void update()
{
		
	glutTimerFunc(50, updateCollisionEnemiBullet, 0);
	glutTimerFunc(50, updateCollisionEnemiPlayer, 0);
	glutTimerFunc(10, updateEnemi, 1);
	glutTimerFunc(300, updateLine, 2);
	glutTimerFunc(50, updateBullet, 2);
	glutTimerFunc(30, updateNewEnemi, 3);
	glutTimerFunc(20, updateDeleateEnemi, 4);
	glutTimerFunc(50, updateDeleteBullet, 5);

	glutTimerFunc(100, moveplayer, 2);  	
    
}