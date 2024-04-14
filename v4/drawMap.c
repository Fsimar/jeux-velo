#ifdef __APPLE_CC__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdio.h>
#include <stdlib.h>


#include "loadMap.h"
#include "drawMap.h"
#include "player.h"
#include "chooseMap.h"
#include "enemi.h"
#include "bullet.h"
#include "line.h"


void drawSky()
{
        glBegin(GL_POLYGON); 
            //glColor3f(0.196078,0.6,0.8);
	    glColor3f(0.0,0.0,0.0); 
            glVertex3f(Square_size, 30*Square_size, 0);
            glVertex3f(Square_size, Square_size, 0);
            glVertex3f(30*Square_size, 0, 0);
            glVertex3f(30*Square_size, 30*Square_size, 0);
        glEnd();
}
void drawString(float x, float y, char *string) //draw text
{
  	glRasterPos2f(x, y);
	glColor3f(1.0f, 0.0f, 0.0f);
  	for (char* c = string; *c != '\0'; c++) 
	{
    	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, *c);  
  	}
	glEnd();//?????????????
}


void drawWall(int mX, int mY)			// fonction qui affiche les objets
{

	for (int j = 0; j < mX; ++j)
	{
		for (int i = 0; i < mY; ++i)
		{
			
		int char_map;	
			
		char_map=*(*(map + j) + i);	
		switch(char_map){

			case '0'://bordures latérales
			{
                glColor3f(1.0f,1.0f,1.0f);
				glMatrixMode(GL_MODELVIEW);
				
			        glLoadIdentity();
				glTranslatef(i*Square_size,j*Square_size,0.0f);
				
				
				glBegin(GL_QUADS);
				glColor3f(0.0,1.0,0.0);
				glVertex3f(0.0f, 0.0f, 0.0f);
				glVertex3f(Square_size, 0.0f, 0.0f);
				glVertex3f(Square_size,Square_size, 0.0f);
				glVertex3f(0.0f,Square_size, 0.0f);

				glEnd();
					
			}
			break;
			case '7'://maxy player
			{
                glColor3f(1.0f,1.0f,1.0f);
				glMatrixMode(GL_MODELVIEW);
				
			        glLoadIdentity();
				glTranslatef(i*Square_size,j*Square_size,0.0f);
				
				
				glBegin(GL_QUADS);
				glColor3f(0.0,1.0,0.0);
				glVertex3f(0.0f, 0.0f, 0.0f);
				glVertex3f(Square_size, 0.0f, 0.0f);
				glVertex3f(Square_size,Square_size, 0.0f);
				glVertex3f(0.0f,Square_size, 0.0f);

				glEnd();
					
			}
			break;
			
			case '1'://route
			{
				glColor3f(0.0f,0.0f,0.0f);

				glMatrixMode(GL_MODELVIEW);
				glLoadIdentity();
				glTranslatef(i*Square_size,j*Square_size,0.0f);
				
				glBegin(GL_QUADS);
					glVertex3f(0.0f, 0.0f, 0.0f);
					glVertex3f(Square_size, 0.0f, 0.0f);
					glVertex3f(Square_size,Square_size, 0.0f);
					glVertex3f(0.0f,Square_size, 0.0f);

				glEnd();
			}
			break;


			case '2'://ligne blanche
			glColor3f(1.0f,1.0f,1.0f);

				glMatrixMode(GL_MODELVIEW);
				glLoadIdentity();
				glTranslatef(i*Square_size,j*Square_size,0.0f);
				
				glBegin(GL_QUADS);
					glVertex3f(0.0f, 0.0f, 0.0f);
					glVertex3f(Square_size, 0.0f, 0.0f);
					glVertex3f(Square_size,Square_size, 0.0f);
					glVertex3f(0.0f,Square_size, 0.0f);

				glEnd();
			
			break;

			case'3'://enemis
			{
	 			glColor3f(1.0f,0.0f,0.0f);

	 			glMatrixMode(GL_MODELVIEW);
				
	 			glLoadIdentity();
	 			glTranslatef(i*Square_size,j*Square_size,0.0f);
	 			glBegin(GL_QUADS);

	 			glVertex3f(1.0f, 0.0f, 0.0f);
	 			glVertex3f(Square_sizeE, 0.0f, 0.0f);
	 			glVertex3f(Square_sizeE,Square_sizeE, 0.0f);
	 			glVertex3f(0.0f,Square_sizeE, 0.0f);

	 			glEnd();	
					
			}	
			break;

			

		case'5'://tirs
			{
			glColor3f(01.0f,1.0f,1.0f);

				glMatrixMode(GL_MODELVIEW);
				glLoadIdentity();
				glTranslatef(i*Square_size/2,j*Square_size/2,0.0f);
				
				glBegin(GL_QUADS);
					glVertex3f(0.6f, 1.0f, 1.0f);
					glVertex3f(Square_size, 0.0f, 0.0f);
					glVertex3f(Square_size,Square_size, 0.0f);
					glVertex3f(0.0f,Square_size, 0.0f);

				glEnd();
			}
			break;
			
			case '6'://route,limite deplacement y
			{
				glColor4f(0.0f,0.0f,0.0f,0.0f);

				glMatrixMode(GL_MODELVIEW);
				glLoadIdentity();
				glTranslatef(i*Square_size,j*Square_size,0.0f);
				
				glBegin(GL_QUADS);
					glVertex3f(0.0f, 0.0f, 0.0f);
					glVertex3f(Square_size, 0.0f, 0.0f);
					glVertex3f(Square_size,Square_size, 0.0f);
					glVertex3f(0.0f,Square_size, 0.0f);

				glEnd();
			}
			break;
			
		
			}

		
			
			}
	}
}
void drawPlayer(player p)
{
	int i, j;
	i = p->pos.x;
	j = p->pos.y;
	
	
	glColor3f(0.0f,1.0f,0.0f);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(j*Square_size,i*Square_size,0.0f);

	glBegin(GL_QUADS);

	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(Square_sizeE, 0.0f, 0.0f);
	glVertex3f(Square_sizeE,Square_sizeE, 0.0f);
	glVertex3f(0.0f,Square_sizeE, 0.0f);

	glEnd();

// TEXTURE
	//int i, j;
	//i = p->pos.x;
	//j = p->pos.y;
	
	//glColor3f(1.0f,1.0f,1.0f);
	//glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();
	
	//int	texture;	
	//glGenTextures(1,&texture);	
	//glBindTexture(GL_TEXTURE_2D,texture);	
	//glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE	);	
	//gluBuild2DMipmaps(GL_TEXTURE_2D,patate2.bytes_per_pixel,patate2.width,patate2.height,GL_RGB,GL_UNSIGNED_BYTE,patate2.pixel_data);	
	//glEnable(GL_TEXTURE_2D);	
	//

	//glTranslatef(j*Square_size,i*Square_size,0.0f);

	//glBegin(GL_QUADS);

	//glTexCoord2f(0.0,0.0);glVertex3f(0.0f, 0.0f, 0.0f);
	//glTexCoord2f(1.0,0.0);glVertex3f(5*Square_sizeE, 0.0f, 0.0f);
	//glTexCoord2f(1.0,1.0);glVertex3f(5*Square_sizeE,5*Square_sizeE, 0.0f);
	//glTexCoord2f(0.0,1.0);glVertex3f(0.0f,5*Square_sizeE, 0.0f);

	//glEnd();
	//glDisable(GL_TEXTURE_2D);	
}

void drawBullet(bulletP p)
{
	int i, j;
	i = p->pos.x;
	j = p->pos.y;
	glColor3f(1.0f, 1.0f, 1.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(j*Shoot_size,i*Shoot_size,0.0f);
	glBegin(GL_QUADS);
	glVertex3f(0.0f,0.0f,0.0f);
	glVertex3f(Shoot_size,0.0f,0.0f);
	glVertex3f(Shoot_size,Shoot_size,0.0f);
	glVertex3f(0.0f,Shoot_size,0.0f);
	glEnd();
}
void drawAllBullet(listeBulletP t)
{
	bulletP first = malloc(sizeof(bullet));
	bulletP next = malloc(sizeof(bullet));
	first = t->starList;
	if (t->starList != NULL && t->starList->nextptr != NULL)
	{
	next = t->starList->nextptr;
	}
	if (t->starList != NULL || t->endList != NULL)
	{
		drawBullet(first);
		if (t->starList->nextptr != NULL)
		{
			drawBullet(next);
			while (next->nextptr != NULL)
			{
				next = next->nextptr;
				drawBullet(next);
			}
		}
	}
}
void drawEnemi(enemiP e)	
{
	int i, j;
	i = e->pos.x;
	j = e->pos.y;
	glColor3f(1.0f,1.0F,0.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(j*Square_size,i*Square_size,0.0f);
	glBegin(GL_QUADS);
	glVertex3f(0.0f,0.0f,0.0f);
	glVertex3f(Square_sizeE,0.0f,0.0f);
	glVertex3f(Square_sizeE,Square_sizeE,0.0f);
	glVertex3f(0.0f,Square_sizeE,0.0f);
	glEnd();
}
void drawAllEnnemi(listeEnemiP e)
{	
	enemiP first = malloc(sizeof(enemi));
	enemiP next = malloc(sizeof(enemi));
	first = e->starList;
	next = e->starList->nextptr;
	if (e->starList != NULL || e->endList != NULL)
	{
		drawEnemi(first);
		if (e->starList->nextptr != NULL)
		{
			drawEnemi(next);
			while (next->nextptr != NULL)
			{
				next = next->nextptr;
				drawEnemi(next);
			}
		}
	}
}

void drawLine(lineP lineL)	
{
	int i, j;
	i = lineL->pos.x;
	j = lineL->pos.y;
	glColor3f(1.0f,1.0F,1.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(j*Square_size,i*Square_size,0.0f);
	glBegin(GL_QUADS);
	glVertex3f(0.0f,0.0f,0.0f);
	glVertex3f(Square_size,0.0f,0.0f);
	glVertex3f(Square_size,Square_size,0.0f);
	glVertex3f(0.0f,Square_size,0.0f);
	glEnd();
}
void drawAllLine(listeLineP lineL)
{	
	lineP first = malloc(sizeof(line));
	lineP next = malloc(sizeof(line));
	first = lineL->starList;
	next = lineL->starList->nextptr;
	if (lineL->starList != NULL || lineL->endList != NULL)
	{
		drawLine(first);
		if (lineL->starList->nextptr != NULL)
		{
			drawLine(next);
			while (next->nextptr != NULL)
			{
				next = next->nextptr;
				drawLine(next);
			}
		}
	}
}

