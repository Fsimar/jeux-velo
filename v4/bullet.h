#ifndef _TIRS_H_
#define _TIRS_H_

#include <stdbool.h>

#include "player.h"



typedef struct bullet *bulletP; 
typedef struct listeBullet *listeBulletP;
bulletP createBullet(player p);
listeBulletP  initialListeBullet();
void insertionBullet(listeBulletP t, bulletP base);
void suppressionBullet(listeBulletP t, int test);
void shoot(player p, listeBulletP t);
extern bulletP r;
extern listeBulletP t;

#endif