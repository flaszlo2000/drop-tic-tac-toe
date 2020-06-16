/**
	@author Levente Löffler
	@version 1.2.5 6/16/2020

	Implementation of the init module.
*/

#define _CRT_SECURE_NO_WARNINGS //this is for msvc
#include "init.h"
#include <stdio.h>
#include <malloc.h>



void init(game_data* data)
{
	printf("Please enter the number of players (0,1,2): ");
	while (1)
	{
		if (scanf("\n%hhu", &data->nPlayers) == 0)
		{
			printf("Not a number. Please retry: ");
			while (getchar() != '\n');
			continue;
		}

		if (data->nPlayers == 0 || data->nPlayers == 1 || data->nPlayers == 2)
			break;
		
		printf("The number of players must be 0, 1, or 2! Please retry: ");
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
	
	data->nP1_wins = 0;
	data->nP2_wins = 0;
}



void reset(map_data* map)
{
	for (char c = 0; c < map->x; c++)
		for (char d = 0; d < map->y; d++)
			map->pMap[c][d] = '0';
}



void uninit(map_data* map)
{
	for (char c = 0; c < map->x; c++)
		free(map->pMap[c]);
		
	free(map->pMap);
}