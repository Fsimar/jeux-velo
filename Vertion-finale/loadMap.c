#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "loadMap.h"
#include "chooseMap.h"
#include "line.h"
#include "save.h"
int **map;



bool loadMap(int maxX, int maxY)		//fonction qui ouvre le fichier txt et charge la carte dans le tableau
{    
    FILE *f = NULL;
    if (choose_map==0)
	{
    	f = fopen("map_accueil.txt", "r");
	}
	if (choose_map==1)
	{
   		f = fopen("map1.txt", "r");
	}
	if (choose_map==2)
	{
    	f = fopen("map_load.txt", "r");
	}
	if (choose_map==3)
	{
    	f = fopen("map_score.txt", "r");
	}
	if (choose_map==4)
	{
    	f = fopen("map_setting.txt", "r");
	}
	if (choose_map==5)
	{
    	f = fopen("map_save.txt", "r");
	}
	if (choose_map==6)//if load game select the correct save
	{
		if (curentSaveLoded==1)
		{
			f = fopen("SaveMap1.txt", "r");
		}
		if (curentSaveLoded==2)
		{
			f = fopen("SaveMap2.txt", "r");
		}
		if (curentSaveLoded==3)
		{
			f = fopen("SaveMap3.txt", "r");
		}
		if (curentSaveLoded==4)
		{
			f = fopen("SaveMap4.txt", "r");
		}
		if (curentSaveLoded==5)
		{
			f = fopen("SaveMap5.txt", "r");
		}    	
	}
	if (choose_map==10)
	{
    	f = fopen("map_intro.txt", "r");
	}
	//start of the real funct
    if(f == NULL)
    {
        printf("file empty");
        return false;
    }
	map = malloc(sizeof(char *) * maxX);	
    int c;
    int i=0;
    int j = 0;
	
	*(map + i) = malloc(sizeof(char *) * maxY);	//parcour l'ensemble du fichier map ouvert et le charge
	for(i = 0; i < maxX; i++)
		{
		*(map + i) = malloc(sizeof(char *) * maxY);	
			for(j = 0; j < maxY; j++)
			{		
				c = fgetc(f);
				*(*(map + i) + j) = c;
			}
			fgetc(f);
		}

	    fclose(f);
	
	if (choose_map==1||choose_map==6)
	{
		lodeLine( maxX, maxY);
	}	
	//print les map dans la console
	/* printf("\n"); 

	for(i = 0; i < maxX; i++)
	{
		for(j = 0; j < maxY; j++)
		{
			printf("%c", *(*(map + i) + j));
		}
		printf("\n");
	}
	*/		
 return true;
 }		

