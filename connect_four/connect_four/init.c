/**
Implementation of the init module.
*/

#define _CRT_SECURE_NO_WARNINGS //this is for msvc
#include "init.h";
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
		scanf("%hhu %hhu", &data->map.x, &data->map.y);

		if (data->map.x != 0 && data->map.y != 0)
			break;

		printf("Both dimensions must be greater than 0! Please retry: ");
	}

	data->map.pMap = malloc(data->map.x); //this needs to be freed later

	for (unsigned char c = 0; c < data->map.x; c++)
	{
		data->map.pMap[c] = malloc(data->map.y); //these also need to be freed later

		for (unsigned char d = 0; d < data->map.y; d++)
			data->map.pMap[c][d] = '0';
	}

	printf("If you would like to play a tournament, enter the number of rounds (0, if no tournament): ");
	while (1)
	{
		unsigned char torna;
		scanf("%hhu", &torna);

		if (torna < 0)
		{
			printf("The number of rounds cannot be negative! Please retry: ");
			continue;
		}

		if (!torna)
			data->torna = NULL;
		else
		{
			data->torna = malloc(sizeof(torna_data)); //this also needs to be freed later
			data->torna->nRounds = torna;
			data->torna->nP1_wins = 0;
			data->torna->nP2_wins = 0;
		}

		break;
	}
}