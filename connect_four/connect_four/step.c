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
	scanf("%d", s);
}

int check(game_data* data, char* s) {
	if (*s < '1' || *s > data->map.x - 1 || data->map.pMap[0][*s] != '0')
		return 0;
	else
		return 1;
}

void stepInput(game_data* data, char* s, short* r) {
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

		if (check(data, s))
			break;
		else
			printf("This step is not possible! Please retry: ");
	}
}

void stepPerform(game_data* data, char* s, short* r){}

void step(game_data* data, short* r) {
	char step;
	
	stepInput(data, &step, r);

	stepPerform(data, &step, r);

}