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

//initielize the liste containing the middle line of the map
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


//create a new element (line)
lineP createLine(int x,int y)
{	
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

//insert a new element(line) in the list 
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


//deleat all the data from the list (make the list clean and new ^^)
void cleanListeLine(listeLineP l)
{
	lineP base = l->starList;
	if (l->starList!=NULL)
	{	
 	  	while(base->nextptr!= NULL)
    	{
			base=base->nextptr;
			base->prevptr=NULL;
			l->starList->nextptr=NULL;
			free(l->starList);
			l->starList=base;
			l->quantite--;
		}
		
	l->endList = NULL;
	l->starList = NULL;
	}
}

//lode all the points forming the middle line from the map.text
listeLineP lodeLine(int mX, int mY )			
{   
	lineL=initialListeLine();	
    
	if (choose_map==1 ||choose_map==6)
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
        }
    }
return lineL;  
}   
            
