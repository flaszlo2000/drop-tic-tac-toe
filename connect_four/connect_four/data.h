/**
	@author Levente Löffler
	@version 1.0.1 6/12/2020

	This header declares the necessary data structures used by other modules.
*/

#pragma once

typedef struct map_data
{
	unsigned char x;
	unsigned char y;
	unsigned char** pMap;
} map_data;



typedef struct game_data
{
	unsigned char nPlayers;
	unsigned char nWins;
	unsigned char nP1_wins;
	unsigned char nP2_wins;
	map_data map;
} game_data;