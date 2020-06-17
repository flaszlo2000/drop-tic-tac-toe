/**
	@author Levente Löffler
	@version 1.3.0 6/17/2020

	Implementation of the init module.
*/

#define _CRT_SECURE_NO_WARNINGS //this is for msvc
#include "init.h"
#include "turn.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>



void init(game_data* data)
{
	printf("Please enter the number of players (0,1,2): ");
	char nPlayers;
	while (1)
	{
		if (scanf("%hhu", &nPlayers) == 0)
		{
			printf("Not a number. Please retry: ");
			while (getchar() != '\n');
			continue;
		}

		if (nPlayers == 0 || nPlayers == 1 || nPlayers == 2)
			break;
		
		printf("The number of players must be 0, 1, or 2! Please retry: ");
	}


	player_data* pTempPlayer1 = malloc(sizeof(player_data));
	player_data* pTempPlayer2 = malloc(sizeof(player_data));
	pTempPlayer1->cWins = 0;
	pTempPlayer2->cWins = 0;
	switch (nPlayers)
	{
		case 0:
			pTempPlayer1->sName = "AI";
			pTempPlayer2->sName = "AI";
			pTempPlayer1->fTurn = &ai_turn;
			pTempPlayer2->fTurn = &ai_turn;
			break;

		case 1:
			pTempPlayer1->sName = "TEMPPLAYER1";//placeholder
			pTempPlayer2->sName = "AI";
			pTempPlayer1->fTurn = &player_turn;
			pTempPlayer2->fTurn = &ai_turn;
			break;

		case 2:
			pTempPlayer1->sName = "TEMPPLAYER1";//placeholder
			pTempPlayer2->sName = "TEMPPLAYER2";//placeholder
			pTempPlayer1->fTurn = &player_turn;
			pTempPlayer2->fTurn = &player_turn;
	}


	srand(time(NULL)); 
	switch (rand() % 2)
	{
	case 0:
		data->pP1 = pTempPlayer1;
		data->pP2 = pTempPlayer2;
		break;

	case 1:
		data->pP1 = pTempPlayer2;
		data->pP2 = pTempPlayer1;
	}


	printf("Please enter the dimensions of the map (rows-columns, 2-26): ");
	while (1)
	{
		if (scanf("%hhu%hhu", &data->map.x, &data->map.y) == 0)
		{
			printf("Not numbers. Please retry: ");
			while (getchar() != '\n');
			continue;
		}

		if (data->map.x >= 2 && data->map.y >= 2 && data->map.x <= 26 && data->map.y <= 26)
			break;

		if (data->map.x < 2 || data->map.y < 2)
		{
			printf("Both dimensions must be at least 2! Please retry: ");
			continue;
		}
			
		if (data->map.x > 26 || data->map.y > 26)
			printf("Neither dimension can be greater than 26! Please retry: ");
	}


	data->map.pMap = malloc(data->map.x * sizeof(unsigned char*));
	for (unsigned char c = 0; c < data->map.x; c++)
	{
		data->map.pMap[c] = malloc(data->map.y * sizeof(unsigned char));

		for (unsigned char d = 0; d < data->map.y; d++)
			data->map.pMap[c][d] = '0';
	}


	printf("Please enter the number of marks that have to be in a row in order to win: ");
	while (1)
	{
		if (scanf("%hhu", &data->lLength) == 0)
		{
			printf("Not a number. Please retry: ");
			while (getchar() != '\n');
			continue;
		}

		if ((data->lLength <= data->map.x || data->lLength <= data->map.y) && data->lLength > 1)
			break;

		if (data->lLength <= 1)
		{
			printf("This number must be greater than 1! Please retry: ");
			continue;
		}

		printf("This number must be lower than the greater dimension! Please retry: ");
	}


	printf("Please enter the number of won rounds needed to win the whole game (1-255): ");
	while (1)
	{
		if (scanf("%hhu", &data->nWins) == 0)
		{
			printf("Not a number. Please retry: ");
			while (getchar() != '\n');
			continue;
		}

		if (data->nWins >= 1)
			break;

		printf("The number of won rounds must be positive! Please retry: ");
	}
}



void reset(map_data* map)
{
	for (char c = 0; c < map->x; c++)
		for (char d = 0; d < map->y; d++)
			map->pMap[c][d] = '0';
}



void uninit(game_data* game)
{
	free(game->pP1);
	free(game->pP2);

	for (char c = 0; c < game->map.x; c++)
		free(game->map.pMap[c]);
	free(game->map.pMap);
}