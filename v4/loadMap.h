#ifndef _LOADMAP_H_
#define _LOADMAP_H_

#include <stdbool.h>

#define Square_size 10.0
#define Square_sizeE (4*Square_size) 
#define Shoot_size 10.0

extern int **map;
extern int mX;
extern int mY;


bool loadMap(int maxX, int maxY);

#endif
