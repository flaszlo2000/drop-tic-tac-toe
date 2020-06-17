/**
	@author Tamara S�li
	@author Levente L�ffler
	@version 1.3.0 6/17/2020

	Implementation of the turn module.
*/

#define _CRT_SECURE_NO_WARNINGS
#include "turn.h"
#include <stdio.h>



char ai_turn(game_data* data, unsigned char round) {
	printf("AI making its turn now.\n");
	return 'A'; //placeholder
}



char player_turn(game_data* data, unsigned char round) {
	char step;

	printf("%s, make your move: ", round % 2 ? data->pP1->sName : data->pP2->sName);

	while (1)
	{
		scanf("\n%c", &step);
		if (check_step(&data->map, &step))
			return step;
	}
}



char step_input(game_data* data, unsigned char round) {
	printf("This is the %hhu. turn.\n", round);

	if (round % 2)
		return data->pP1->fTurn(data, round);
	return data->pP2->fTurn(data, round);
}



void step_perform(map_data* map, char step, unsigned char round) {
	unsigned char ch = round % 2 ? '1' : '2';

	for (int i = map->x - 1; i >= 0; i--) {
		if (map->pMap[i][step - 'A'] == '0') {
			map->pMap[i][step - 'A'] = ch;
			break;
		}
	}
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



void turn(game_data* data, unsigned char round) {
	step_perform(&data->map, step_input(data, round), round);
}