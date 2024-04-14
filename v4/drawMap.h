#ifndef _DRAWMAP_H_
#define _DRAWMAP_H_

#include "loadMap.h"
#include "player.h"
#include "bullet.h"
#include "enemi.h"
#include "line.h"

void drawWall(int mX, int mY);
void drawBullet(bulletP p);
void drawPlayer(player p);
void drawEnemi(enemiP e);
void drawBullet(bulletP p);
void drawLine(lineP linept);	
void drawAllEnnemis(listeEnemiP e);
void drawAllBullet(listeBulletP t);
void drawAllLine(listeLineP lineL);
#endif
