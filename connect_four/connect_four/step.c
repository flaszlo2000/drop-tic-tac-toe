/**
Implementation of the step module.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "data.h"
#include "step.h"

void aiTurn(game_data* data, char* s) {}

void playerTurn(game_data* data, char* s) {

	printf("Please enter your step!");
	scanf("%hhu", s);
}

int check(game_data* data, char* s) {
	if (*s < '1' || *s > data->map.x - 1 || data->map.pMap[0][*s] != '0')
		return 0;
	else
		return 1;
}

void stepInput(game_data* data, char* s, char* r) {
	while (1) {
		switch (data->nPlayers) {
		case 0:
			aiTurn(data, s);
			break;

		case 1:
			if (*r % 2 == 1)
				playerTurn(data, s);
			else
				aiTurn(data, s);
			break;

		case 2:
			playerTurn(data, s);
			break;
		}

		if (check(data, s)) {
			*r += 1;
			break;
		} else
			printf("This step is not possible! Please retry: ");
	}
}

void stepPerform(game_data* data, char* s, char* r){
	char ch = (*r % 2 ? "X" : "O");

	for (int i = data->map.x - 1; i >= 0; i--) {
		if (data->map.pMap[i][*s] == 0) {
			data->map.pMap[i][*s] = ch;
			break;
		}
	}
}

void step(game_data* data, char* r) {
	char step;
	
	stepInput(data, &step, r);

	stepPerform(data, &step, r);

}