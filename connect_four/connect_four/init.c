/**
	Implementation of the init module.
*/

#define _CRT_SECURE_NO_WARNINGS //this is for msvc
#include "init.h";
#include <stdio.h>
#include <malloc.h>



void init(struct data* game_data)
{
	printf("Please enter the number of players (0,1,2): ");
	while (1)
	{
		scanf("%hhu", &game_data->nPlayers);

		if (game_data->nPlayers != 0 && game_data->nPlayers != 1 && game_data->nPlayers != 2)
		{
			printf("Invalid number! The number of players must be 0, 1, or 2! Please retry: ");
			continue;
		};

		break;
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
			game_data->torna = NULL;
		else
		{
			game_data->torna = malloc(sizeof(struct torna));
			game_data->torna->nRounds = torna;
			game_data->torna->nP1_wins = 0;
			game_data->torna->nP2_wins = 0;
		}

		break;
	}
}