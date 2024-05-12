#ifndef _LINE_H_
#define _LINE_H_

#include <stdbool.h>

#include "player.h"
#include "loadMap.h"


typedef struct line *lineP; 
typedef struct listeLine *listeLineP;
lineP createLine(int mX, int mY);
listeLineP  initialListeLine();
void insertionLine(listeLineP lineL, lineP base);

void cleanListeLine(listeLineP l);
listeLineP lodeLine(int mX, int mY);

extern lineP linept;
extern listeLineP lineL;

#endif