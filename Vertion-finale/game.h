#ifndef _GAME_H_
#define _GAME_H_

#include <stdio.h>
#include <stdlib.h>
#include "player.h"
#include "enemi.h"
#include "bullet.h"
#include "line.h"

void Keyboard(unsigned char key, int x, int y);
void keyUp (unsigned char key, int x, int y) ;
void game(int maxX, int maxY, player p, listeEnemiP e, listeBulletP  t,listeLineP lineL);//
void launchGameFromSave ();
void cleanAllList();
void loadAllList();

extern bool pauseg;
extern bool gameover;
extern bool UP ;
extern bool LEFT ;
extern bool RIGHT ;
extern bool DOWN ;
extern bool SHOOT ;
extern char* curentName;
extern int weapon;
extern int bullettype1;
extern int bullettype2;
extern int LvL;
extern int baseEnemiSponeSpeed;
extern int EnemiSponeSpeed;

#endif
