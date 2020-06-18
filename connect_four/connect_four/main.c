/**
	@author Levente L�ffler
	@author Tamara S�li
	@version 1.2.3 6/17/2020

	Main function and game loop.
*/

#define _CRT_SECURE_NO_WARNINGS
#include "init.h"
#include "display.h"
#include "map_check.h"
#include "turn.h"
#include <stdio.h>



void game_loop(game_data* game, unsigned char nRound)
{
	printf("\n");
	for (unsigned char c = 0; c < 20; c++)
		printf("#");
	printf("\n%s %hhu - %hhu %s\n", game->pP1->sName, game->pP1->cWins, game->pP2->cWins, game->pP2->sName);
	printf("\nRound %hhu begins.\n", nRound);
	for (unsigned char c = 0; c < 20; c++)
		printf("#");
	printf("\n");

	unsigned short nTurn = 1;

	while (true)
	{
		display(&game->map);

		turn(game, nTurn);
		//break; // FIXME: for test

		if (check_win(game, nTurn))
		{
			nTurn % 2 ? game->pP1->cWins++ : game->pP2->cWins++;
			display(&game->map);
			printf("%s won this round!\n", nTurn % 2 ? game->pP1->sName : game->pP2->sName);
			for (unsigned char c = 0; c < 20; c++)
				printf("-");
			printf("\n");
			return;
		}

		if (check_draw(&game->map))
		{
			display(&game->map);
			printf("The round has come to a draw!\n");
			for (unsigned char c = 0; c < 20; c++)
				printf("-");
			printf("\n");
			return;
		}

		nTurn++;
	}
}



int main()
{
	bool repeat = true;

	while (repeat)
	{
		game_data game;

		init(&game);

		for (unsigned char c = 1; game.pP1->cWins < game.nWins && game.pP2->cWins < game.nWins; c++)
		{
			game_loop(&game, c);

			if (game.nWins > 1)
			{
				player_data* tmp = game.pP1;
				game.pP1 = game.pP2;
				game.pP2 = tmp;
				reset(&game.map);
			}	
		//break; // FIXME: to test
		}
		
		printf("\n");
		for (unsigned char c = 0; c < 20; c++)
			printf("~");
		printf("\n");
		printf(game.pP1->cWins == game.pP2->cWins ? "The match has come to a draw.\n" : "Victory! %s has won the match!\n", game.pP1->cWins < game.pP2->cWins ? game.pP2->sName : game.pP1->sName);
		for (unsigned char c = 0; c < 20; c++)
			printf("~");
		printf("\n");

		uninit(&game);

		printf("\nWould you like to play again? (y/n): ");
		char input;

	readrepeat:
		while (true)
		{
			scanf("\n%c", &input);

			char temp = getchar();
			while (temp != '\n')
			{
				temp = getchar();
				if (temp == '\n')
				{
					printf("Too many characters. Please retry: ");
					goto readrepeat;
				}
			}

			if (input == 'n')
			{
				repeat = false;
				break;
			}

			if (input == 'y')
				break;
			else
				printf("Please answer with \"y\" or \"n\"! Retry: ");
		}
	}

	return 0;
}