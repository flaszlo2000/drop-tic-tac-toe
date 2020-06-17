/**
	@author Tamara Süli
	@author Levente Löffler
	@version 1.0.9 6/17/2020

*/


#pragma once
#include "data.h"

void turn(game_data* data, unsigned char round);

char step_input(game_data* data, unsigned char round);

void step_perform(map_data* data, char step, unsigned char round);

char ai_turn(game_data* data, unsigned char round);

char player_turn(game_data* data, unsigned char round);

int check_step(map_data* map, char* step);