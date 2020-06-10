#pragma once
/**
	@author Levente Löffler
	@version 1.0.1 6/9/2020

	This module is responsible for the initialization of the data structure of a match.
	It reads information such as the number of players and whether the game is played in tournament mode.
	It also defines the necessary data structures.
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



void init(game_data* game_data);