/**
	@author Tamara S�li
	@author Levente L�ffler
	@author Fazekas László
	@version 1.3.1 6/17/2020

	Implementation of the turn module.
*/

#define _CRT_SECURE_NO_WARNINGS
#include "turn.h"
#include "ai.h"
#include <stdio.h>



char ai_turn(map_data* map, char* sName, unsigned short round, unsigned char goal) {
	printf("%s making its turn now.\n", sName);
	char result = ai_main(map, round, goal);

	printf("ai decision: %c\n", result);
	return result;
}



char player_turn(map_data* map, char* sName, unsigned short round, unsigned char goal) { // atm goal args is unused bc the givel data structure is not compatible
	char step;

	printf("%s, make your move: ", sName);

	while (1)
	{
		scanf("\n%c", &step);
		if (check_step(map, &step))
			return step;
	}
}



char step_input(game_data* data, unsigned short round) {
	printf("This is the %hu. turn.\n", round);

	if(round % 2) {
		return data->pP1->fTurn(&data->map, data->pP1->sName, round, data->lLength);
	} else {
		return data->pP2->fTurn(&data->map, data->pP2->sName, round, data->lLength);
	}
}



void step_perform(map_data* map, char step, unsigned short round) {
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



void turn(game_data* data, unsigned short round) {
	step_perform(&data->map, step_input(data, round), round);
}