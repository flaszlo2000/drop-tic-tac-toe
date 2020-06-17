/**
	@author Tamara Süli
	@author Levente Löffler
	@version 1.2.0 6/17/2020

	Implementation of the turn module.
*/

#define _CRT_SECURE_NO_WARNINGS
#include "turn.h"
#include <stdio.h>

void ai_turn(game_data* data, char* step) {}

void player_turn(game_data* data, char* step) {

	scanf("\n%c", step);
}

int check_step(map_data* map, char* step) {
	char temp = getchar();
	while (temp != '\n')
	{
		temp = getchar();
		if (temp == '\n')
		{
			printf("Too many characters. Please retry: ");
			return 0;
		}	
	}

	if ((*step < 'A' || *step >= map->y + 'A') && (*step < 'a' || *step >= map->y + 'a'))
	{
		printf("Incorrect column. Please retry: ");
		return 0;
	}

	if (*step >= 'a' && *step < map->y + 'a')
		*step -= 'a' - 'A';

	if (map->pMap[0][*step - 'A'] == '0')
		return 1;

	printf("The column is full. Please retry: ");
	return 0;
}

void step_input(game_data* data, char* step, unsigned char round) {
	printf("This is the %hhu. turn.\n", round);
	printf("%s, make your move: ", round % 2 ? data->pP1->sName : data->pP2->sName);
	
	while (1) {
		if (round % 2)
			data->pP1->fTurn(data, step);
		else
			data->pP2->fTurn(data, step);

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