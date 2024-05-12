#ifndef _score_H_
#define _score_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "player.h"

void sort_array(int length, int tab[length],int tabn[length]);
bool loadBestScoreChart();
bool loadBestScoreNameChart();
bool saveBestScoreChart();
bool saveBestScoreNameChart();



void updatebestscorechartScoreAndName();

bool loadDataFromSave(int n);
void laodAllDataFromSave();


void SaveMapAndData (int nsave);
//void SaveMap(int maxX, int maxY);
bool SaveData(int nsave);
bool SaveMapdata(int maxX, int maxY,int nsave);

char* NameFromInt(int nameint);

extern int bestscorechart[10];
extern int currentscorechart[11];
extern int bestscoreNamechartint[10];

extern int currentscoreNamechartint[11];
extern char* nom1;
extern char* nom2;
extern char* nom3;
extern char* nom4;
extern char* nom5;
extern int curentNameInt;
extern int curentSaveLoded;



extern int datasave0[7];
extern int datasave1[7];
extern int datasave2[7];
extern int datasave3[7];
extern int datasave4[7];
extern int datasave5[7];


#endif