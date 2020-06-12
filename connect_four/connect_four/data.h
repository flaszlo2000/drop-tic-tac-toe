#pragma once
/**
	@author Levente Löffler
	@version 1.0.0 6/12/2020

	This header declares the necessary data structures used by other modules.
*/



typedef struct torna_data
{
	unsigned char nRounds;
	unsigned char nP1_wins;
	unsigned char nP2_wins;
} torna_data;



typedef struct map_data
{
	unsigned char x;
	unsigned char y;
	unsigned char** pMap;
} map_data;



typedef struct game_data
{
	unsigned char nPlayers;
	map_data map;
	torna_data* torna;
} game_data;