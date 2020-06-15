/**
	@author Tamara Süli
	@author Levente Löffler
	@version 1.0.6 6/15/2020

*/


#pragma once
#include "data.h"

void ai_turn(game_data* data, int* step, unsigned char round);

void player_turn(game_data* data, int* step, unsigned char round);

int check_step(game_data* data, int* step);

void step_input(game_data* data, int* step, unsigned char round);

void step_perform(game_data* data, int* step, unsigned char round);

void turn(game_data* data, unsigned char round);