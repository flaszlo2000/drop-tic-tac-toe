/**
	@author Tamara Süli
	@version 1.0.0 6/12/2020

	
*/

void aiTurn(game_data* data, char* sx, char* sy, short* r);

void playerTurn(game_data* data, char* sx, char* sy, short* r);

int check(game_data* data, char* x, char* y);

void stepInput(game_data* data, char* sx, char* sy, short* r);

void stepPerform(game_data* data, char* sx, char* sy);