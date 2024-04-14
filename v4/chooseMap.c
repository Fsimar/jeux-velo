#include <GL/glut.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "loadMap.h"
#include "drawMap.h"
#include "chooseMap.h"



void Choose_map(int choose_map){
  
if (choose_map==0)
{
    f = fopen("map_accueil.txt", "r");

}
if (choose_map==1)
{
    f = fopen("map1.txt", "r");

}
if (choose_map==2)
{
    f = fopen("map_save.txt", "r");

}
if (choose_map==3)
{
    f = fopen("map_score.txt", "r");

}
if (choose_map==4)
{
    f = fopen("map_setting.txt", "r");

}
if (choose_map==5)
{
    f = fopen("map_pause.txt", "r");

}
}