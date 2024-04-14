#ifndef _GAME_H_
#define _GAME_H_

#include <stdio.h>
#include <stdlib.h>
#include "player.h"
#include "enemi.h"
#include "bullet.h"
#include "line.h"

void Keyboard(unsigned char key, int x, int y);
void game(int maxX, int maxY, player p, listeEnemiP e, listeBulletP  t,listeLineP lineL);//


#endif
