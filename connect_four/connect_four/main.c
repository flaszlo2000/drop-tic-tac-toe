/**
	@author Levente Löffler
	@author Tamara Süli
	@version 1.2.1 6/17/2020

	Main function and game loop.
*/

#define _CRT_SECURE_NO_WARNINGS
#include "init.h"
#include "display.h"
#include "map_check.h"
#include "turn.h"
#include <stdio.h>



void game_loop(game_data* game)
{
	printf("Round begins.\n");

	unsigned char nTurn = 1;

	while (true)
	{
		display(&game->map);

		turn(game, nTurn);

		if (check_win(game, nTurn))
		{
			nTurn % 2 ? game->pP1->cWins++ : game->pP2->cWins++;
			display(&game->map);
			printf("%s won this round!\n", nTurn % 2 ? game->pP1->sName : game->pP2->sName);
			return;
		}

		if (check_draw(&game->map))
		{
			display(&game->map);
			printf("The round has come to a draw!\n");
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

		while (game.pP1->cWins < game.nWins && game.pP2->cWins < game.nWins)
		{
			game_loop(&game);
			if (game.nWins > 1)
				reset(&game.map);
		}
			
		printf(game.pP1->cWins == game.pP2->cWins ? "The match has come to a draw.\n" : "Victory! %s has won the match!\n", game.pP1->cWins < game.pP2->cWins ? game.pP2->sName : game.pP1->sName);

		uninit(&game);

		printf("Would you like to play again? (y/n): ");
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