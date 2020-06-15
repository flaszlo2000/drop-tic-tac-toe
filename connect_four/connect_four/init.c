/**
	@author Levente Löffler
	@version 1.1.0 6/15/2020

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
		scanf("%hhu", &data->nPlayers);

		if (data->nPlayers == 0 || data->nPlayers == 1 || data->nPlayers == 2)
			break;
		
		printf("The number of players must be 0, 1, or 2! Please retry: ");
	}

	printf("Please enter the dimensions of the map (rows-columns, 1-255): ");
	while (1)
	{
		scanf("%hhu%hhu", &data->map.x, &data->map.y);

		if (data->map.x != 0 && data->map.y != 0)
			break;

		printf("Both dimensions must be greater than 0! Please retry: ");
	}

	data->map.pMap = malloc(data->map.x * sizeof(unsigned char*));

	for (unsigned char c = 0; c < data->map.x; c++)
	{
		data->map.pMap[c] = malloc(data->map.y * sizeof(unsigned char));

		for (unsigned char d = 0; d < data->map.y; d++)
			data->map.pMap[c][d] = '0';
	}

	printf("Please enter the number of won rounds needed to win the whole game (1-255): ");
	while (1)
	{
		scanf("%hhu", &data->nWins);

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