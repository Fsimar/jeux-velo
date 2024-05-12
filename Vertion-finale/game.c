#ifdef __APPLE_CC__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "loadMap.h"
#include "drawMap.h"
#include "game.h"
#include "chooseMap.h"
#include "bullet.h"
#include "enemi.h"
#include "line.h"

#include "player.h"
#include "save.h"

bool UP = false;
bool LEFT = false;
bool RIGHT = false;
bool DOWN = false;
bool SHOOT = false;

player p;

//clean all the chained list
void cleanAllList()
{
	cleanListeEnnemi(e);
	cleanListeBullet(t);
	cleanListeLine(lineL);
}

//load all the chained list from the data on map
void loadAllList()
{
	lodeLine(mX, mY);
	lodeEnemi(mX,mY);
	lodeBullet(mX, mY);
}

//take the data from the save and register it as the current one (manage all that is necessary to launch a game from a save)
void launchGameFromSave ()
{
	choose_map=6;
	cleanAllList();
	loadMap(mX, mY);
	loadAllList();
	free(p);
	p=createPlayer(mX, mY);
	int currentdataloded[7]={0};
	if (curentSaveLoded==1)
	{
		for (int i = 0; i < 6; i++)
		{		
		currentdataloded[i]=datasave1[i];		       
		}
	}
	if (curentSaveLoded==2)
	{
		for (int i = 0; i < 6; i++)
		{		
		currentdataloded[i]=datasave2[i];		       
		}
	}
	if (curentSaveLoded==3)
	{
		for (int i = 0; i < 6; i++)
		{		
		currentdataloded[i]=datasave3[i];		       
		}
	}
	if (curentSaveLoded==4)
	{
		for (int i = 0; i < 6; i++)
		{		
		currentdataloded[i]=datasave4[i];		       
		}
	}
	if (curentSaveLoded==5)
	{
		for (int i = 0; i < 6; i++)
		{		
		currentdataloded[i]=datasave5[i];		       
		}
	}
			
	curentNameInt=currentdataloded[0];
	curentName=NameFromInt(curentNameInt);
	p->life=currentdataloded[1];
	p->score=currentdataloded[2];
	LvL =p->score %(50);
	EnemiSponeSpeed=baseEnemiSponeSpeed;
	for (int i = 0; i < LvL; i++)
	{
		EnemiSponeSpeed-=50;
	}	
	weapon =currentdataloded[3];
	bullettype1=currentdataloded[4];
	bullettype2=currentdataloded[5];

	pauseg=false;
	gameover=false;	
}

//if a key is realesed set the displasement fonction to false (when the key is holed down continue to move)eneble diagonale displacement
void keyUp (unsigned char key, int x, int y) 
{  
	switch(key)
	{
		case'q':			
			LEFT = false;			
		break;
		
		case'd':			
			RIGHT = false;				
		break;	

		case's':			
			DOWN = false;						
		break;
	
		/*case ' ':		
			SHOOT = false;				
		break;	*/
		
		case'z':				
			UP = false;				
		break;
	}
} 
 
//manage all key pressed and the action that need to be taken if a key is pressed depending of the current state of the game
void Keyboard(unsigned char key, int x, int y)  // fonction allant gérer les input
{
		
	switch(key)
	{
		case 27://manage the ascape game from the menu and the paus while in game
			if (choose_map==0)
			{
				saveBestScoreChart();
				saveBestScoreNameChart();
				
				exit(0);
			}
			
			if ((choose_map==1||choose_map==6)&&gameover==false)//if playing go to pause menu
			{
				if (pauseg==false)
				{
					pauseg=true;//pause/					
				}
				
				else if (pauseg==true)
				{
					pauseg=false;//pause/					
				}			
			}
			
		break;

		case'c'://go to commend pannel
			if (choose_map==0)
			{
				choose_map=4;//commend
				loadMap(mX, mY);
			}			
		break;

		case'd'://go right when in game
			if (choose_map==1||choose_map==6)
				{
				RIGHT = true;
				}
		break;

		case 'e':// escape from a menu to the previous on or to the mane menu
			if (choose_map<5 ||choose_map==6)
			{
				if (pauseg==true)
				{				
					updatebestscorechartScoreAndName();	
					saveBestScoreChart();
					saveBestScoreNameChart();			
					choose_map=0;//accueil
					loadMap(mX, mY);
					gameover=false;
				}			
			}
			if (choose_map==5)
			{
				if (curentSaveLoded==0)
				{
					choose_map=1;
					loadMap(mX, mY);
				}
				if (curentSaveLoded!=0)
				{
					choose_map=6;
					loadMap(mX, mY);
				}			
			}
		break;			

		case'g'://launch a new game from main menu or if game is lost
			if (choose_map==0)//from main menu
			{
				choose_map=1;//if accueil go to game
				curentSaveLoded=0;//nouvelle game ne depend pas des maps sauvegardées
				loadMap(mX, mY);
				cleanAllList();
				lodeLine(mX,  mY );
				free(p);
				p=createPlayer(mX, mY);
				weapon =1;
				bullettype1=10;
				bullettype2=5;
				LvL =0;
				EnemiSponeSpeed=baseEnemiSponeSpeed;
				pauseg=false;				
			}

			if ((choose_map==1||choose_map==6)&& gameover==true)
			{
				choose_map=1;//from game over go to new game
				curentSaveLoded=0;
				updatebestscorechartScoreAndName();
				saveBestScoreChart();
				saveBestScoreNameChart();
				cleanAllList();
				loadMap(mX, mY);
				lodeLine(mX,  mY );
				free (p);
				p=createPlayer(mX, mY);
				weapon =1;
				bullettype1=10;
				bullettype2=5;
				LvL =0;
				EnemiSponeSpeed=baseEnemiSponeSpeed;
				pauseg=false;
				gameover=false;
			}
		break;

		case'l'://go to load pannel from main menu and from game in pause or lost
			if (choose_map==0)
			{
				choose_map=2;
				loadMap(mX, mY);
			}
			if (((choose_map==1||choose_map==6))&&(gameover==true||pauseg==true))//if gwhant to load a game
			{
				updatebestscorechartScoreAndName();
				saveBestScoreChart();
				saveBestScoreNameChart();
				choose_map=2;
				loadMap(mX, mY);				
			}						
		break;
		
		case'n'://go to choise of name panel		
			if (choose_map==0)
			{
				choose_map=10;//name
				loadMap(mX, mY);
			}			
		break;
		
		case'o'://go to best score pannel
			if (choose_map==0)
				{
					choose_map=3;
					loadMap(mX, mY);
				}
			if ((choose_map==1||choose_map==6)&&gameover==true)//if game lost and want to go to score
			{
				updatebestscorechartScoreAndName();
				saveBestScoreChart();
				saveBestScoreNameChart();
				choose_map=3;
				loadMap(mX, mY);
				gameover=false;
			}
		break;

		case'q'://move left if ingame			
			if (pauseg==false)
			{
				LEFT = true;				
			}			
		break;

		case'r'://realode if ingame 			
			if ((choose_map==1||choose_map==6)&&pauseg==false)
			{
				if (bullettype1==0 && weapon ==1)
				{
					bullettype1=10;
				}
				if (bullettype2==0 && weapon ==2)
				{
					bullettype2=5;
				}
								
			}			
		break;

		case's'://go down if in gamee and go to save menu if game in pause
			if ((choose_map==1||choose_map==6) && pauseg==false)//if game in pause not lost cango to save
			{
				DOWN= true;				
			}
			if ((choose_map==1||choose_map==6)&&(gameover==false&&pauseg==true))//if game in pause not lost cango to save
			{
				choose_map=5;
				
				loadMap(mX, mY);				
			}							
		break;

		case'z'://go up if in game
			if (choose_map==1||choose_map==6)
			{
				UP = true;				
			}
		break;

		case ' '://shoot if ingame
		if ((choose_map==1||choose_map==6))
			{
			SHOOT = true;
			}
		break;			
	
//select name/save/load from number 1 to 5  (choose_map=10 : choice of name \choose_map=5 : save map\choose_map=2 : load map)
	case'1':
		if (choose_map==10)
		{
			choose_map=0;
			loadMap(mX, mY);
			curentName=nom1;		
			curentNameInt=1;					
		}	
		if (choose_map==5)// si map = save
		{			
			SaveMapAndData (1);
			laodAllDataFromSave();
									
		}
		if (choose_map==2)// si map = load
		{			
			curentSaveLoded=1;
			launchGameFromSave ();					
		}

		break;
	case'2':
		if (choose_map==10)
		{
			choose_map=0;
			loadMap(mX, mY);
			curentName=nom2;			
			curentNameInt=2;
				
		}
		if (choose_map==5)// si map = save
		{	
			SaveMapAndData (2);	
			laodAllDataFromSave();	
						
		}
		if (choose_map==2)// si map = load
		{			
			curentSaveLoded=2;
			launchGameFromSave ();							
		}	
		break;
	case'3':
		if (choose_map==10)
		{
			choose_map=0;
			loadMap(mX, mY);
			curentName=nom3;			
			curentNameInt=3;	
		}
		if (choose_map==5)// si map = save
		{
			SaveMapAndData (3);	
			laodAllDataFromSave();
			
		}
		if (choose_map==2)// si map = load
		{			
			curentSaveLoded=3;
			launchGameFromSave ();	
		}
		break;		
	case'4':
		if (choose_map==10)
		{
			choose_map=0;
			loadMap(mX, mY);
			curentName=nom4;			
			curentNameInt=4;	
		}
		if (choose_map==5)// si map = save
		{
			SaveMapAndData (4);	
			laodAllDataFromSave();
		}
		if (choose_map==2)// si map = load
		{			
			curentSaveLoded=4;
			launchGameFromSave ();							
		}
		break;	
	case'5':
		if (choose_map==10)
		{
			choose_map=0;
			loadMap(mX, mY);
			curentName=nom5;		
			curentNameInt=5;	
		}
		if (choose_map==5)// si map = save
		{
			SaveMapAndData (5);	
			laodAllDataFromSave();
		}
		if (choose_map==2)// si map = load
		{			
			curentSaveLoded=5;
			launchGameFromSave ();	
									
		}
		break;	
	}
}


// manage all the part that nned to be displayed depending of the state  of the game and set the gameover variable if the game is lost call the key mangement
void game(int mX, int mY, player p,listeEnemiP e,listeBulletP t,listeLineP lineL)//
{
	drawWall(mX, mY);			//afficher le fond
	
	if (choose_map==10)
	{
		drawChooseName();
	}	
	
	if (choose_map==0 )
	{
		drawMenu();
	}

	if (choose_map==2 ||choose_map==5)
	{
		drawLoadMenu();		
	}

	if (choose_map==3 )
	{
		drawScoreMenu();		
	}
	if (choose_map==4 )
	{
		drawSettingsMenu()	;		
	}	

	if (choose_map==1||choose_map==6)// draw all the relevent data if playing new or saved game
	{			
		if (t->starList != NULL || t->endList != NULL)
		{
			drawAllBullet(t);	
		}	
		if (lineL->starList != NULL || lineL->endList != NULL)
		{
			drawAllLine(lineL);	
		}
		if (e->starList != NULL || e->endList != NULL)
		{
			drawAllEnnemi(e);	
		}		
		drawPlayer(p);
		if (pauseg==1 && gameover==false) //si le game est en pause dessine le menu pause
		{
			drawPauseMenu();
		}
	
		drawScore();			
		drawVie();
		drawName();
		drawBulletNumber();
		if (p->life==0)//if gameover
		{
			gameover=true;
			pauseg=1;
			drawGameOver();			
		}
		if (p->score%(50)==0 &&(50*LvL!=p->score))//increase the spaning rate of ennemi every 50 score
		{
			LvL++;
			EnemiSponeSpeed-=50;
		}		
	}		
	glutKeyboardFunc(Keyboard);		//fonction de glut gérant le clavier
	glutKeyboardUpFunc(keyUp);	
	glutPostRedisplay();
}

