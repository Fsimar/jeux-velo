#ifndef _PLAYER_H_
#define _PLAYER_H_

typedef struct 
{
	
	int nbr_bullet;
	int dmg;
	int fire_rate;

}Weapon;



typedef struct
{
	int x;
	int y;
}position;


typedef struct bullet bullet;
struct bullet
{
	
	int life;
	int dmg;
	position pos;
	struct bullet *prevptr;
	struct bullet *nextptr;
};

typedef struct listeBullet listeBullet;

struct listeBullet
{
	
	int quantite;
	struct bullet *starList;
	struct bullet *endList;
	
};





struct play
{
	int life;
	int  hit_point;
	int spead;
	position pos;
	Weapon weapon;
};

typedef struct play *player;

typedef struct enemi enemi;

struct enemi
{
	int life;
	int  hit_point;
	int spead;
	position pos;
	Weapon weapon;
	struct enemi *prevptr;
	struct enemi *nextptr;
};

extern player p;





typedef struct listeEnemi ListeEnemi; 

struct listeEnemi
{
	
	int quantite;
	struct enemi *starList;
	struct enemi *endList;
	
};

typedef struct line line;
struct line
{
	position pos;
	struct line *prevptr;
	struct line *nextptr;

};
typedef struct listeLine listeLine;

struct listeLine
{
	
	int quantite;
	struct line *starList;
	struct line *endList;
	
};

player createPlayer(int mX, int mY);
void moveLeft(player p);
void moveRight(player p);
void moveUp(player p);
void moveDown(player p);

#endif
