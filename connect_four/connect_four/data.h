/**
	@author Levente L�ffler
	@author Fazekas László
	@version 1.2.3 6/18/2020

	This header declares the necessary data structures used by other modules.
*/

#ifndef DATA_H
#define DATA_H

typedef struct map_data
{
	unsigned char x;
	unsigned char y;
	unsigned char** pMap;
} map_data;



typedef struct player_data
{
	char* sName;
	char (*fTurn)(map_data*, char*, unsigned short, unsigned char);
	unsigned char cWins;
} player_data;



typedef struct game_data
{
	unsigned char nWins;
	unsigned char lLength;
	player_data* pP1;
	player_data* pP2;
	map_data map;
} game_data;

#endif