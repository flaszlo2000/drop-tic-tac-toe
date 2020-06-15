/**
Implementation of the turn module.
*/

#define _CRT_SECURE_NO_WARNINGS
#include "turn.h"
#include <stdio.h>

void ai_turn(game_data* data, int* step, char* round) {}

void player_turn(game_data* data, int* step, char* round) {

	printf("This is the %hhu. turn.\n", *round);
	printf(*round % 2 ? "1. player" : "2. player");
	printf(", please enter your step!");
	scanf("%d", step);
}

int check_step(game_data* data, int* step) {
	if (*step < 1 || *step > data->map.x || data->map.pMap[0][*step-1] != '0')
		return 0;
	else
		return 1;
}

void step_input(game_data* data, int* step, char* round) {
	while (1) {
		switch (data->nPlayers) {
		case 0:
			ai_turn(data, step, round);
			break;

		case 1:
			if (*round % 2 == 1)
				player_turn(data, step, round);
			else
				ai_turn(data, step, round);
			break;

		case 2:
			player_turn(data, step, round);
			break;
		}

		if (check_step(data, step, round)) {
			break;
		}
		else
			printf("This step is not possible! Please retry: ");
	}
}

void step_perform(game_data* data, int* step, char* round) {
	unsigned char ch = *round % 2 ? '1' : '2';

	for (int i = data->map.x - 1; i >= 0; i--) {
		if (data->map.pMap[i][*step - 1] == '0') {
			data->map.pMap[i][*step - 1] = ch;
			break;
		}
	}
}

void turn(game_data* data, char* round) {
	int step;

	step_input(data, &step, round);

	step_perform(data, &step, round);

}