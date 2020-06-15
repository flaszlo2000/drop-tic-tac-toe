/**
	@author Tamara Süli
	@version 1.0.0 6/15/2020

*/


#pragma once
#include "data.h"

void ai_turn(game_data* data, int* s);

void player_turn(game_data* data, int* s);

int check_step(game_data* data, int* s);

void step_input(game_data* data, int* s, char* r);

void step_perform(game_data* data, int* s, char* r);

void turn(game_data* data, char* r);