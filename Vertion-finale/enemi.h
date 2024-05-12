#ifndef _ENEMIES_H_
#define _ENEMIES_H_

#include "player.h"



typedef struct enemi *enemiP; 
typedef struct listeEnemi *listeEnemiP;
enemiP createEnemi(int *maxY);
listeEnemiP  initialListEnemi();
void insertionEnemi(listeEnemiP e, enemiP q);
void suppressionEnemi(listeEnemiP e, int test);
void cleanListeEnnemi(listeEnemiP e);
enemiP createEnemiFromMap(int x,int y);
listeEnemiP lodeEnemi(int mX, int mY);
extern enemiP q;
extern listeEnemiP e;

#endif