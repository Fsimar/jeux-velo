#ifdef __APPLE_CC__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "loadMap.h"
#include "player.h"
#include "line.h"
#include "chooseMap.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

lineP linept;
listeLineP lineL;

listeLineP  initialListeLine()
{
	listeLineP lineL = malloc(sizeof(listeLine));
	if (lineL == NULL)
	{
		exit(EXIT_FAILURE);
	}
	lineL->starList = NULL;
	lineL->endList = NULL;
	lineL->quantite = 0;
	return lineL;
}
lineP createLine(int x,int y)
{
	
	y +=1;
	lineP new = malloc(sizeof(line));
	if (new == NULL)
	{
		exit(EXIT_FAILURE);
	}
	new->pos.x = x;
	new->pos.y = y;
	new->nextptr = NULL;
	new->prevptr = NULL;
	
	return new;
}



 

void insertionLine(listeLineP lineL, lineP base)
{
	lineP new = malloc(sizeof(line));
	if (new == NULL)
	{
		exit(EXIT_FAILURE);
	}
	new = base;
	if (lineL->starList == NULL || lineL->endList == NULL)
	{
		lineL->endList = new;
		lineL->starList = new;
	}
	else
	{
		new->nextptr = lineL->starList;
		lineL->starList->prevptr = new;
		lineL->starList = new;
	}
	lineL->quantite += 1;
}

listeLineP lodeLine(int mX, int mY )			// fonction qui cree la ligne centrale en fct de la carte
{   
	lineL=initialListeLine();
	printf("ok\n");
    
	if (choose_map==1 ||choose_map==2)
    {
	
        
	    for (int j = 0; j < mX; ++j)
	    {
		    for (int i = 0; i < mY; ++i)
		    {
					   	
                if (*(*(map + j) + i)=='5')
            
                { 
                    lineP new = createLine(j,i);
	                insertionLine(lineL, new);
                    
                }  
              
            }
        }printf("%d",lineL->quantite);
    }
return lineL;
  
}   
            
