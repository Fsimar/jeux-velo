#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "loadMap.h"
#include "chooseMap.h"
#include "line.h"
#include "player.h"
#include "save.h"
#include "game.h"
#include "chooseMap.h"


int bestscorechart[10]={0};
int currentscorechart[11];
int bestscoreNamechartint[10]={0};

int currentscoreNamechartint[11];
//int Savedscorechart[4]={0};
//char$ SavedNamechart[4];

char* nom1="Remco";
char* nom2="Patrick";
char* nom3="Wouter";
char* nom4="Eddy";
char* nom5="Tom";
int curentNameInt;

int datasave0[7]={0};
int datasave1[7]={0};
int datasave2[7]={0};
int datasave3[7]={0};
int datasave4[7]={0};
int datasave5[7]={0};


void updatebestscorechartScoreAndName()
{
    for ( int i = 0; i < 10; i++)
    {
        currentscorechart[i]=bestscorechart[i];
        currentscoreNamechartint[i]=bestscoreNamechartint[i];
        //printf("name %s,score %d\n",currentscoreNamechart[i],currentscorechart[i]);
    }
    
    currentscorechart[10]=p->score;
    currentscoreNamechartint[10]=curentNameInt;
    
    sort_array(11,currentscorechart,currentscoreNamechartint);

    for ( int i = 0; i < 10; i++)
    {
       bestscorechart[i]=currentscorechart[i];
       bestscoreNamechartint[i]=currentscoreNamechartint[i];

       //printf("name %s,score %d\n",currentscoreNamechart[i],currentscorechart[i]);
    }

}

// Préconditions: length est un int >0
// Postconditions: sort array name and score with score from high to low
void sort_array(int length, int tab[length],int tabn[length]) {
    
    int i,j;
    int max=0;
    int maxn=0;
    for(i=0;i<length;i++) {
        
        for(j=i+1;j<length;j++) {
            if (tab[i] < tab[j]) 
            {
                max = tab[i];
                maxn=tabn[i];
                tab[i] = tab[j];
                tabn[i]=tabn[j];
                tab[j] = max;
                tabn[j]= maxn;
            }
        }    
        
    }
}


bool loadBestScoreChart()		//fonction qui charge le tableau des scors
{
    
    FILE* f = NULL;
    
    f = fopen("bestscorechart.txt", "r");

	if(f == NULL)
    {
        printf("file empty");
        return false;
    }
    
    fscanf(f,"%d %d %d %d %d %d %d %d %d %d",&bestscorechart[0],&bestscorechart[1],&bestscorechart[2],&bestscorechart[3],&bestscorechart[4],&bestscorechart[5],&bestscorechart[6],&bestscorechart[7],&bestscorechart[8],&bestscorechart[9]);
    
	fclose(f);
   
 return true;
}	


bool saveBestScoreChart()		//fonction qui charge le tableau des scors
{    
    FILE* f = NULL;
    
    f = fopen("bestscorechart.txt", "w");
	
    if(f == NULL)
    {
        printf("file empty");
        return false;
    }
    
    fprintf(f,"%d %d %d %d %d %d %d %d %d %d",bestscorechart[0],bestscorechart[1],bestscorechart[2],bestscorechart[3],bestscorechart[4],bestscorechart[5],bestscorechart[6],bestscorechart[7],bestscorechart[8],bestscorechart[9]);
    
	fclose(f);
   
 return true;
 }

bool loadBestScoreNameChart()		//fonction qui charge le tableau des scors (nom)
{   
    FILE* f = NULL;
    
    f = fopen("bestscoreNamechart.txt", "r");
	
    if(f == NULL)
    {
        printf("file empty");
        return false;
    }
    
    fscanf(f,"%d %d %d %d %d %d %d %d %d %d",&bestscoreNamechartint[0],&bestscoreNamechartint[1],&bestscoreNamechartint[2],&bestscoreNamechartint[3],&bestscoreNamechartint[4],&bestscoreNamechartint[5],&bestscoreNamechartint[6],&bestscoreNamechartint[7],&bestscoreNamechartint[8],&bestscoreNamechartint[9]);
    
	fclose(f);
   
 return true;
}	

bool saveBestScoreNameChart()		//fonction qui charge le tableau des scors (nom)
{  
    FILE* f = NULL;
    
    f = fopen("bestscoreNamechart.txt", "w");
	
    if(f == NULL)
    {
        printf("file empty");
        return false;
    }
    
    fprintf(f,"%d %d %d %d %d %d %d %d %d %d",bestscoreNamechartint[0],bestscoreNamechartint[1],bestscoreNamechartint[2],bestscoreNamechartint[3],bestscoreNamechartint[4],bestscoreNamechartint[5],bestscoreNamechartint[6],bestscoreNamechartint[7],bestscoreNamechartint[8],bestscoreNamechartint[9]);
    
	fclose(f);
   
 return true;
}	

//save le nom la vie et les munissions du player lorsqu il selectionne une des 5 save
bool SaveData(int nsave)
{
    
    FILE* f = NULL;

    if (nsave==1)
    {
        f = fopen("SaveMap1Data.txt", "w");
    }
    
    if (nsave==2)
    {
        f = fopen("SaveMap2Data.txt", "w");
    }

    if (nsave==3)
    {
        f = fopen("SaveMap3Data.txt", "w");
    }

	if (nsave==4)
    {
        f = fopen("SaveMap4Data.txt", "w");
    }

    if (nsave==5)
    {
        f = fopen("SaveMap5Data.txt", "w");
    }

    if(f == NULL)
    {
        printf("file empty");
        return false;
    }
    //Player name(int),vie,score,currentwepon,bulletwepon1,bulletwepon2
    fprintf(f,"%d %d %d %d %d %d",curentNameInt,p->life,p->score,weapon,bullettype1,bullettype2);
    
	fclose(f);
   
 return true;
}	

//fonction qui charge les données en fct de la save choisie(toutes les données de la partie hormis la map)
bool loadDataFromSave(int n)		
{   
    FILE* f = NULL;
    int n1 [6];

    if (n==1)
    {
        f = fopen("SaveMap1Data.txt", "r");
    }
    if (n==2)
    {
        f = fopen("SaveMap2Data.txt", "r");
    }
    if (n==3)
    {
        f = fopen("SaveMap3Data.txt", "r");
    }
	if (n==4)
    {
        f = fopen("SaveMap4Data.txt", "r");
    }
    if (n==5)
    {
        f = fopen("SaveMap5Data.txt", "r");
    }
	
    if(f == NULL)
    {
        printf("file empty");
        return false;
    }
    
    fscanf(f,"%d %d %d %d %d %d",&n1[0],&n1[1],&n1[2],&n1[3],&n1[4],&n1[5]);

    for (int i = 0; i < 6; i++)
    {
        if (n==1)
        {
            datasave1[i]=n1[i];
        }
        if (n==2)
        {
            datasave2[i]=n1[i];
        }
        if (n==3)
        {
            datasave3[i]=n1[i];
        }
        if (n==4)
        {
            datasave4[i]=n1[i];
        }
        if (n==5)
        {
            datasave5[i]=n1[i];
        }        
    }    
	fclose(f);
return true;
}

//charge les data des 5 save (nom player score... ! pas la map) sert pour les draw des menu save et load
void laodAllDataFromSave()
{
    loadDataFromSave(1);
    loadDataFromSave(2);
    loadDataFromSave(3);
    loadDataFromSave(4);
    loadDataFromSave(5); 
}

//charge le nom du joueur (string) selon le nom du player en int 
char* NameFromInt(int nameint)
{
    char*name;
    if (nameint==1)
    {
        name=nom1;
    }
    if (nameint==2)
    {
        name=nom2;
    }
    if (nameint==3)
    {
        name=nom3;
    }
    if (nameint==4)
    {
        name=nom4;
    }
    if (nameint==5)
    {
        name=nom5;
    }
    return name;
}


//save les data de la game actuelle et la map (la map contient pos player/enemi/bullet/line)
void SaveMapAndData (int nsave)
{
   SaveData(nsave);
   SaveMapdata(mX,mY,nsave); 
}


//save la map de jeux actuelle sur le .txt choisi
bool SaveMapdata(int maxX, int maxY,int nsave)
{
    FILE* f = NULL;

    if (nsave==1)
    {
        f = fopen("SaveMap1.txt", "w");
    }
    if (nsave==2)
    {
        f = fopen("SaveMap2.txt", "w");
    }
    if (nsave==3)
    {
        f = fopen("SaveMap3.txt", "w");
    }
	if (nsave==4)
    {
        f = fopen("SaveMap4.txt", "w");
    }
    if (nsave==5)
    {
        f = fopen("SaveMap5.txt", "w");
    }

    if(f == NULL)
    {
        printf("file empty");
        return false;
    }

    int i=0;
    int j = 0;
    for(i = 0; i < maxX; i++)
    {
        for(j = 0; j < maxY+1; j++)
        {
            r = t->starList;
            linept = lineL->starList;
            q = e->starList;
            int test=0; // test si un caractere a été ecrit s assure de necrire qu un caractere par pos

            if ((j<4||(j>110&&j<116))&&test==0)//inscrit lesbordures vertes
            {
               fputc('0',f);
               test=1;
            }
            if (j==117&&test==0)//inscrit le saut de ligne
            {
               fputc('\n',f);
               test=1;
            }
            
            if ((j==4||j==110)&&test==0)//inscrit les lignes blanches latérales
            {
               fputc('2',f);
               test=1;
            }
            if (j==116&&test==0)//inscrit les / en fin de ligne
            {
               fputc('/',f);
               test=1;
            }
           
            if (lineL->starList != NULL &&test==0)//dessine la ligne blanche centrale
            {
                if (linept->pos.x==i && linept->pos.y==j)
                {
                    fputc('5',f);
                    test=1;                   
                }
                while (linept->nextptr != NULL && test==0)
                {
                    linept = linept->nextptr;
                    if (linept->pos.x==i&&linept->pos.y==j)
                    {
                        fputc('5',f);
                        test=1;                        
                    }
                }
            }
            
            if (p->pos.x==i&&p->pos.y==j)
            {
                if (test==1)
                {
                   p->pos.y++;
                }
                if (test==0)
                {
                    fputc('4',f);
                    test=1;
                }
                //dans le cas ou le player est sur une ligne blanche centrale déplace légerement le player vers la droite avant enregistrement                              
            }

	        if (t->starList != NULL&&test==0) //dessine les tirs présents dans la liste chainée
	        {			
                if (r->pos.x==i&&r->pos.y==j)
                {
                    fputc('6',f);
                    test=1;
                }
                while (r->nextptr != NULL && test==0)
                {
                    r = r->nextptr;
                    if (r->pos.x==i&&r->pos.y==j)
                    {
                        fputc('6',f);
                        test=1;
                    }
			    }
		    }      
          
            if (e->starList != NULL&&test==0)
            {               
                if (q->pos.x==i&&q->pos.y==j)
                {
                    fputc('3',f);
                    test=1;
                }
                while (q->nextptr != NULL && test==0)
                {
                    q = q->nextptr;
                    
                    if (q->pos.x==i&&q->pos.y==j)
                    {
                      fputc('3',f);
                      test=1;  
                    }
                }
            }	

            if (test==0) //si aucun carractere na ete ecrit ecrire "1"
            {
                fputc('1',f);   
            }
            
            
        }
    }
    return true;
}

