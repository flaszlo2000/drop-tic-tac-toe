/**
Implementation of the step module.
*/

#include <stdio.h>
#include "data.h";
#include "step.h";

void aiTurn(game_data* data, char* sx, char* sy, short* r) {}

void playerTurn(game_data* data, char* sx, char* sy, short* r) {

	printf("Please enter your step!");
	scanf("%hhu%hhu", sx, sy);
}

int check(game_data* data, char* x, char* y) {
	if (*x < 'a' || *x > 'a' + data->map.x - 1 || *y < '0' || *y > data->map.y - 1 || data->map.pMap[*x - 1][*y - 1] != '0')
		return 0;
	else
		return 1;
}

void stepInput(game_data* data, char* sx, char* sy, short* r) {
	while (1) {
		switch (data->nPlayers) {
		case 0:
			aiTurn(data, sx, sy, r);
			break;

		case 1:
			if (*r % 2 == 1)
				playerTurn(data, sx, sy, r);
			else
				aiTurn(data, sx, sy, r);
			break;

		case 2:
			playerTurn(data, sx, sy, r);
			break;
		}

		if (check(data, sx, sy))
			break;
		else
			printf("This step is not possible! Please retry: ");
	}
}

void stepPerform(game_data* data, char* sx, char* sy){}

void step(game_data* data) {
	short round = 1;
	char stepx;
	char stepy;
	
	stepInput(data, &stepx, &stepy, &round);

	stepPerform(data, &stepx, &stepy);

}