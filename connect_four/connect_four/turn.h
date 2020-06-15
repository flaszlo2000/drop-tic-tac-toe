/**
	@author Tamara Süli
	@version 1.0.5 6/15/2020

*/


#pragma once
#include "data.h"

void ai_turn(game_data* data, int* step, char* round);

void player_turn(game_data* data, int* step, char* round);

int check_step(game_data* data, int* step);

void step_input(game_data* data, int* step, char* round);

void step_perform(game_data* data, int* step, char* round);

void turn(game_data* data, char* round);