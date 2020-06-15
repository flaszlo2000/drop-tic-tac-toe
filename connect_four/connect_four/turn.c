/**
Implementation of the turn module.
*/

#define _CRT_SECURE_NO_WARNINGS
#include "turn.h"
#include <stdio.h>

void ai_turn(game_data* data, int* s) {}

void player_turn(game_data* data, int* s) {

	printf("Please enter your step!");
	scanf("%d", s);
}

int check_step(game_data* data, int* s) {
	if (*s < 1 || *s > data->map.x || data->map.pMap[0][*s-1] != '0')
		return 0;
	else
		return 1;
}

void step_input(game_data* data, int* s, char* r) {
	while (1) {
		switch (data->nPlayers) {
		case 0:
			ai_turn(data, s);
			break;

		case 1:
			if (*r % 2 == 1)
				player_turn(data, s);
			else
				ai_turn(data, s);
			break;

		case 2:
			player_turn(data, s);
			break;
		}

		if (check_step(data, s)) {
			break;
		}
		else
			printf("This step is not possible! Please retry: ");
	}
}

void step_perform(game_data* data, int* s, char* r) {
	unsigned char ch = *r % 2 ? '1' : '2';

	for (int i = data->map.x - 1; i >= 0; i--) {
		if (data->map.pMap[i][*s - 1] == '0') {
			data->map.pMap[i][*s - 1] = ch;
			break;
		}
	}
}

void turn(game_data* data, char* r) {
	int step;

	step_input(data, &step, r);

	step_perform(data, &step, r);

}