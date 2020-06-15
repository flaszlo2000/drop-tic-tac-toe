/**
	@author Levente Löffler
	@version 6/15/2020

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

	char nTurn = 1;

	while (true)
	{
		turn(game, &nTurn);

		if (check_win(&game->map, nTurn))
		{
			nTurn % 2 ? game->nP1_wins++ : game->nP2_wins++;
			display(&game->map);
			printf("Player %d won this round!\n", nTurn % 2 ? '1' : '2');
			return;
		}

		display(&game->map);

		if (check_draw(&game->map))
		{
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

		while (game.nP1_wins < game.nWins && game.nP2_wins < game.nWins)
			game_loop(&game);

		printf(game.nP1_wins == game.nP2_wins ? "The match has come to a draw.\n" : "Victory! Player %d has won the match!\n!", game.nP1_wins < game.nP2_wins ? '2' : '1');

		printf("Would you like to play again? y/n: ");
		char input;
		while (true)
		{
			scanf("%c", &input);
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