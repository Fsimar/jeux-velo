#ifndef _bullet_H_
#define _bullet_H_
#include <stdbool.h>

#include "player.h"



typedef struct bullet *bulletP; 
typedef struct listeBullet *listeBulletP;
listeBulletP  initialListeBullet();
bulletP createBullet(player p);
bulletP createBulletFromMap(int x,int y);
void insertionBullet(listeBulletP t, bulletP base);
void suppressionBullet(listeBulletP t, int test);
void cleanListeBullet(listeBulletP b);
listeBulletP lodeBullet(int mX, int mY );
void shoot(player p, listeBulletP t);

extern bulletP r;
extern listeBulletP t;

#endif