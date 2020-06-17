/**
	@author Levente Löffler
	@version 1.2.0 6/17/2020

	This header declares the necessary data structures used by other modules.
*/

#pragma once
typedef struct player_data
{
	char* sName;
	void (*fTurn)();
	unsigned char cWins;
} player_data;



typedef struct map_data
{
	unsigned char x;
	unsigned char y;
	unsigned char** pMap;
} map_data;



typedef struct game_data
{
	unsigned char nWins;
	unsigned char lLength;
	player_data* pP1;
	player_data* pP2;
	map_data map;
} game_data;