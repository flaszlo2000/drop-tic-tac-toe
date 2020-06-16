/**
	@author Tamara Süli
	@author Levente Löffler
	@version 1.1.5 6/16/2020

	Implementation of the turn module.
*/

#define _CRT_SECURE_NO_WARNINGS
#include "turn.h"
#include <stdio.h>

void ai_turn(game_data* data, char* step, unsigned char round) {}

void player_turn(char* step, unsigned char round) {

	printf("This is the %hhu. turn.\n", round);
	printf("Player %c, make your move: ", round % 2 ? '1' : '2');
	scanf("\n%c", step);
	while (getchar() != '\n');
}

int check_step(map_data* map, char* step) {
	if ((*step < 'A' || *step >= map->x + 'A') && (*step < 'a' || *step >= map->x + 'a'))
	{
		printf("Incorrect column. Please retry!\n\n");
		return 0;
	}

	if (*step >= 'a' && *step < map->x + 'a')
		*step -= 'a' - 'A';

	if (map->pMap[0][*step - 'A'] == '0')
		return 1;

	printf("The column is full. Please retry!\n\n");
	return 0;
}

void step_input(game_data* data, char* step, unsigned char round) {
	while (1) {
		switch (data->nPlayers) {
		case 0:
			ai_turn(data, step, round);
			break;

		case 1:
			if (round % 2 == 1)
				player_turn(step, round);
			else
				ai_turn(data, step, round);
			break;

		case 2:
			player_turn(step, round);
			break;
		}

		if (check_step(&data->map, step))
			break;
	}
}

void step_perform(map_data* map, char* step, unsigned char round) {
	unsigned char ch = round % 2 ? '1' : '2';

	for (int i = map->x - 1; i >= 0; i--) {
		if (map->pMap[i][*step - 'A'] == '0') {
			map->pMap[i][*step - 'A'] = ch;
			break;
		}
	}
}

void turn(game_data* data, unsigned char round) {
	char step;

	step_input(data, &step, round);

	step_perform(&data->map, &step, round);

}