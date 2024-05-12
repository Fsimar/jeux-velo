#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#include "enemi.h"
#include "player.h"
#include "bullet.h"
#include "collision.h"
#include "loadMap.h"


//check if there is a collision between an ennemi and a bullet if so put theirs life to 0 and add 1 to score
void CollisionEnemiBullet (enemiP e, bulletP t)
{
	bool colX = false;
	bool colY = false;
    bool col = false;

	if (e->life != 0 && t->life != 0)// evite le compte multiple de la meme collision
	{
		if ( e->pos.x+4>=t->pos.x&&t->pos.x>=e->pos.x+2)//x de e+4 est le dessous du carré de l ennemi on ajoute une fourchette (jusqu a e+2) de facon a ce qu on ai pas de manqué lors de l epdate (quand ex+4=tx)
		{
			colX = true;
		}
		
		if (e->pos.y<=t->pos.y && t->pos.y<=e->pos.y+4 )
		{
			colY = true;
		}
		
		if (colX && colY)
		{
			col = true;
		}
		
		if (col)
		{
			e->life = 0;
			t->life = 0;
			p->score++;
			
			col= false;
			
		}
	}
} 

//check if there is a collision between the player and an ennemi if so delete the ennemi and player loose 1 life
void CollisionEnemiPlayer (enemiP e)
{    
	bool colX = false;
	bool colY = false;
    bool col = false;
	if (e->life != 0)// evite le compte multiple de la meme collision
	{			
		if ( e->pos.x<=p->pos.x+4 && p->pos.x<=e->pos.x+4)//x de e+4 est le dessous du carré de l ennemi on ajoute une fourchette (jusqu a e+2) de facon a ce qu on ai pas de manqué lors de l epdate (quand ex+4=px)
		{
			colX = true;
		}
		
		if (e->pos.y<=p->pos.y+4 && p->pos.y<=e->pos.y+4 )
		{
			colY = true;
		}
		
		if (colX && colY)
		{
			col = true;
		}
		
		if (col)
		{	
			e->life = 0;
			p->life -- ;
			col= false;			
		}
	}
} 