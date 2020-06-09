#pragma once
/**
	@author Levente Löffler
	@version 1.0.1 6/9/2020

	This module is responsible for the initialization of the data structure of a match.
	It reads information such as the number of players and whether the game is played in tournament mode.
	It also defines the necessary data structures.
*/



typedef struct torna
{
	unsigned char nRounds;
	unsigned char nP1_wins;
	unsigned char nP2_wins;
} torna;



typedef struct data
{
	unsigned char nPlayers;
	struct torna* torna;
} data;



void init(struct data* game_data);