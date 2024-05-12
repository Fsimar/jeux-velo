#ifdef __APPLE_CC__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "loadMap.h"
#include "drawMap.h"
#include "player.h"
#include "chooseMap.h"
#include "enemi.h"
#include "bullet.h"
#include "line.h"
#include "game.h"
#include "save.h"

//pre : recoit des pos une string et un font
//post : print la sting au coordonnées et dans la font demanddée (le choix de couleur se fait avant l appel)
void vBitmapOutput(int x, int y, char *string, void *font) 
{
	int len,i; // len donne la longueur de la chaîne de caractères

	glRasterPos2f(x,y); // Positionne le premier caractère de la chaîne
	len = (int) strlen(string); // Calcule la longueur de la chaîne
	for (i = 0; i < len; i++) glutBitmapCharacter(font,string[i]); // Affiche chaque caractère de la chaîne
	
}


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


//pre : recoit la taille de la map
//post : affiche des carrés en fonctions des caractères de la map (dessinne la map de fond)
void drawWall(int mX, int mY)
{
	for (int j = 0; j < mX; ++j)
	{
		for (int i = 0; i < mY; ++i)
		{			
			int char_map;	
				
			char_map=*(*(map + j) + i);	
			switch(char_map)
			{
				case '0'://bordures latérales
					
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
				break;
								
				case '1'://route
				
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
				break;

				case '2'://ligne blanche latérales
					
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

				/*case'3'://enemis
									
				break;


				case'4'://player						
								
				break;
				

				case'5'://midle line (moving one)					
										
				break;


				case'6'://bullet (type1)					
										
				break;
				
			
				case'7'://free (bullet2?)
				
				break;
				case'8'://free (ennemi2?)
				
				break;
				case'9'://free (obstacle ?)
				
				break;*/						
			}
		}	
	}		
}	

//pre : reçoit la struct player
//post : dessiner le player en fonction de sa position
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


//pre : recoit une "bullet"
//post : dessinne une "bullet"sur l ecran
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

//pre : recoit la liste chainée contenant toutes les "bullet"
//post : parcour tout la liste et fait appelle a draw bullet pour chaque élément de la liste (dessine l'ensemble des"bullet")
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

//pre : recoit un "enemi"
//post : dessinne un "enemi"sur l ecran
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

//pre : recoit la liste chainée contenant toutes les "enemit"
//post : parcour tout la liste et fait appelle a drawenemi pour chaque élément de la liste (dessine l'ensemble des"enemi")
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

//pre : recoit une "line"
//post : dessinne une "line"sur l ecran
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

//pre : recoit la liste chainée contenant toutes les "line"
//post : parcour tout la liste et fait appelle a drawline pour chaque élément de la liste (dessine l'ensemble des"line")
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


//post : dessine le text du menu d accueil
void drawMenu(){
	
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(40*Square_size,20*Square_size,0.0f);
	
	glColor3f(1.0f,1.0f,1.0f);	
	vBitmapOutput(0,0,"New Game Press G",GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(1.0f,1.0f,1.0f);
	vBitmapOutput(0,50,"Load Game Press L",GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(1.0f,1.0f,1.0f);
	vBitmapOutput(0,100,"Score Press O",GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(1.0f,1.0f,1.0f);
	vBitmapOutput(0,150,"Controls Press C",GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(1.0f,1.0f,1.0f);
	vBitmapOutput(0,200,"Change Name Press N",GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(1.0f,1.0f,1.0f);
	vBitmapOutput(0,300,"Quit Game Press Esc",GLUT_BITMAP_TIMES_ROMAN_24);
	
}

//post : dessine le text du menu de pause ingame
void drawPauseMenu()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(30*Square_size,20*Square_size,0.0f);

	glColor3f(1.0f,0.5f,1.0f);
	vBitmapOutput(0,0,"Resume Press esc",GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(1.0f,0.5f,1.0f);
	vBitmapOutput(0,50,"Load Game Press L",GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(1.0f,0.5f,1.0f);
	vBitmapOutput(0,100,"Save Press S",GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(1.0f,0.5f,1.0f);
	vBitmapOutput(0,150,"Escape Press E",GLUT_BITMAP_TIMES_ROMAN_24);	
}



//post : dessine le score du joueur pendant la game et pour les menu  pause/gameover
void drawName()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(6*Square_size,4*Square_size,0.0f);

	static char textName[50];	

	sprintf(textName, "Name : %s",curentName);
	char *s=textName;
	
	glColor3f(1.0f,0.5f,1.0f);
	vBitmapOutput(0,0,s,GLUT_BITMAP_TIMES_ROMAN_24);
}

//post : dessine le score du joueur pendant la game et pour les menu  pause/gameover
void drawScore()
{	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(6*Square_size,7*Square_size,0.0f);

	static char textScore[50];
	int score = p->score;

	sprintf(textScore, "Score : %i", score);
	char *s=textScore;
	
	glColor3f(1.0f,0.5f,1.0f);
	vBitmapOutput(0,0,s,GLUT_BITMAP_TIMES_ROMAN_24);
}

//post : dessine la vie du joueur pendant la game et pour les menu  pause/gameover
void drawVie()
{	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(6*Square_size,10*Square_size,0.0f);

	static char textScore[50];
	int score = p->life;

	sprintf(textScore, "Vie : %i", score);
	char *s=textScore;
	
	glColor3f(1.0f,0.5f,1.0f);
	vBitmapOutput(0,0,s,GLUT_BITMAP_TIMES_ROMAN_24);
}

//post : dessine le nombre de balles du joueur pendant la game et dit de recharger si nécéssaire
void drawBulletNumber()
{	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(6*Square_size,13*Square_size,0.0f);

	static char textBullet1[50];
	static char textBullet2[50];
	static char textRealode[50];
	int nbrbul1 = bullettype1;
	int nbrbul2 = bullettype2;

	sprintf(textBullet1, "Ammo 1 : %i", nbrbul1);
	char *s1=textBullet1;	
	glColor3f(1.0f,0.7f,1.0f);
	vBitmapOutput(0,0,s1,GLUT_BITMAP_TIMES_ROMAN_24);

	sprintf(textBullet2, "Ammo 2 : %i", nbrbul2);
	char *s2=textBullet2;	
	glColor3f(1.0f,0.7f,1.0f);
	vBitmapOutput(0,30,s2,GLUT_BITMAP_TIMES_ROMAN_24);

	if ((bullettype1==0 && weapon ==1)||(bullettype2==0 && weapon ==2))
	{
		sprintf(textRealode, "To Realode Press R");
		char *s3=textRealode;	
		glColor3f(1.0f,0.1f,0.1f);
		vBitmapOutput(0,60,s3,GLUT_BITMAP_TIMES_ROMAN_24);
	}	
}

//post : dessine le text du menu de game over quand la vie du player passe a 0
void drawGameOver()
{	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(30*Square_size,20*Square_size,0.0f);

	glColor3f(1.0f,0.0f,0.0f);
	vBitmapOutput(50,-10,"GAME OVER",GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(1.0f,0.5f,1.0f);
	vBitmapOutput(0,50,"NewGame Press G",GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(1.0f,0.5f,1.0f);
	vBitmapOutput(0,100,"Load Game Press L",GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(1.0f,0.5f,1.0f);
	vBitmapOutput(0,150,"Score Press O",GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(1.0f,0.5f,1.0f);
	vBitmapOutput(0,200,"Escape Press E",GLUT_BITMAP_TIMES_ROMAN_24);
}


//affiche les 10 meilleurs scores
void drawScoreMenu()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(40*Square_size,20*Square_size,0.0f);
		
	int Bestscore;
	int y=0;

	for (int i = 0; i < 10; i++)
	{
		static char textBestScore[50];
		static char* n;

		n = NameFromInt(bestscoreNamechartint[i]);
		
		Bestscore=bestscorechart[i];
		sprintf(textBestScore, "%d : %s %i",(i+1),n,Bestscore);
		char *s=textBestScore;
	
		glColor3f(1.0f,1.0f,1.0f);
		vBitmapOutput(0,y,s,GLUT_BITMAP_TIMES_ROMAN_24);
		y+=50;
	}
	glColor3f(1.0f,0.5f,1.0f);
	vBitmapOutput(50,-50,"BEST SCORE",GLUT_BITMAP_TIMES_ROMAN_24);	
	glColor3f(1.0f,1.0f,1.0f);
	vBitmapOutput(-350,-150,"Escape Press E",GLUT_BITMAP_TIMES_ROMAN_24);	
}

//dessine le menu permettant de choisir son nom
void drawChooseName()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(40*Square_size,20*Square_size,0.0f);
	
	static char textnom1[50];
	sprintf(textnom1, "%s Press 1", nom1);
	char *s1=textnom1;
		
	static char textnom2[50];
	sprintf(textnom2, "%s Press 2", nom2);
	char *s2=textnom2;
	
	static char textnom3[50];
	sprintf(textnom3, "%s Press 3", nom3);
	char *s3=textnom3;
	
	static char textnom4[50];
	sprintf(textnom4, "%s Press 4", nom4);
	char *s4=textnom4;

	static char textnom5[50];
	sprintf(textnom5, "%s Press 5", nom5);
	char *s5=textnom5;

	glColor3f(1.0f,0.5F,1.0f);	
	vBitmapOutput(50,-50,"Choose Your Name",GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(1.0f,1.0F,1.0f);	
	vBitmapOutput(0,0,s1,GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(1.0f,1.0F,1.0f);
	vBitmapOutput(0,50,s2,GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(1.0f,1.0F,1.0f);
	vBitmapOutput(0,100,s3,GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(1.0f,1.0F,1.0f);
	vBitmapOutput(0,150,s4,GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(1.0f,1.0F,1.0f);
	vBitmapOutput(0,200,s5,GLUT_BITMAP_TIMES_ROMAN_24);
}

//dessine le menu de la page load game
void drawLoadMenu()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(40*Square_size,20*Square_size,0.0f);
	
	static char save1 [50];
	static char save2 [50];
	static char save3 [50];
	static char save4 [50];
	static char save5 [50];
		
	sprintf(save1,"1: %s vie: %d  score: %d",NameFromInt(datasave1[0]),datasave1[1],datasave1[2]);
	char *s1=save1;
	glColor3f(1.0f,1.0f,1.0f);
	vBitmapOutput(0,0,s1,GLUT_BITMAP_TIMES_ROMAN_24);
		
	sprintf(save2, "2: %s vie: %d  score: %d",NameFromInt(datasave2[0]),datasave2[1],datasave2[2]);
	char *s2=save2;
	glColor3f(1.0f,1.0f,1.0f);
	vBitmapOutput(0,50,s2,GLUT_BITMAP_TIMES_ROMAN_24);

	sprintf(save3, "3: %s vie: %d  score: %d",NameFromInt(datasave3[0]),datasave3[1],datasave3[2]);
	char *s3=save3;
	glColor3f(1.0f,1.0f,1.0f);
	vBitmapOutput(0,100,s3,GLUT_BITMAP_TIMES_ROMAN_24);

	sprintf(save4, "4: %s vie: %d  score: %d",NameFromInt(datasave4[0]),datasave4[1],datasave4[2]);
	char *s4=save4;
	glColor3f(1.0f,1.0f,1.0f);
	vBitmapOutput(0,150,s4,GLUT_BITMAP_TIMES_ROMAN_24);

	sprintf(save5, "5: %s vie: %d  score: %d",NameFromInt(datasave5[0]),datasave5[1],datasave5[2]);
	char *s5=save5;
	glColor3f(1.0f,1.0f,1.0f);
	vBitmapOutput(0,200,s5,GLUT_BITMAP_TIMES_ROMAN_24);

	glColor3f(1.0f,0.5f,1.0f);
	vBitmapOutput(50,-50,"Save Option",GLUT_BITMAP_TIMES_ROMAN_24);	
	glColor3f(1.0f,1.0f,1.0f);
	vBitmapOutput(-350,-150,"Escape Press E",GLUT_BITMAP_TIMES_ROMAN_24);	
}

//dessine le menu de la page setting
void drawSettingsMenu()
{		
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(40*Square_size,20*Square_size,0.0f);
	
	glColor3f(1.0f,0.5f,1.0f);
	vBitmapOutput(50,-50,"Controls And  Settings",GLUT_BITMAP_TIMES_ROMAN_24);	
	glColor3f(1.0f,1.0f,1.0f);
	vBitmapOutput(-350,-150,"Escape Press E",GLUT_BITMAP_TIMES_ROMAN_24);
	
	
	glColor3f(1.0f,1.0f,1.0f);	
	vBitmapOutput(0,0,"Move : Z/Q/S/D",GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(1.0f,1.0f,1.0f);
	vBitmapOutput(0,50,"Shoot : Space Bar",GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(1.0f,1.0f,1.0f);
	vBitmapOutput(0,100,"Realode : R",GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(1.0f,1.0f,1.0f);
	vBitmapOutput(0,150,"Pause : ESC",GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(1.0f,0.2f,0.2f);
	vBitmapOutput(-150,350,"Dont Let Them Touch You! Dont Let Them Through!",GLUT_BITMAP_TIMES_ROMAN_24);	
	
}