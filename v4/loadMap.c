#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "loadMap.h"
#include "chooseMap.h"
#include "line.h"
int **map;

	
bool loadMap(int maxX, int maxY)		//fonction qui ouvre le fichier txt et charge la carte dans le tableau
{
    map = malloc(sizeof(char *) * maxX);	
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
    f = fopen("map_save.txt", "r");

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
    f = fopen("map_pause.txt", "r");

	}
    if(f == NULL)
    {
        printf("file empty");
        return false;
    }
    int c;
    int i=0;
    int j = 0;
	
	*(map + i) = malloc(sizeof(char *) * maxY);	
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
		
	    printf("\n");

		for(i = 0; i < maxX; i++)
		{
			for(j = 0; j < maxY; j++)
			{
				printf("%c", *(*(map + i) + j));
			}
			printf("\n");
		}
				
	lodeLine( maxX, maxY);	
 return true;
 }		

