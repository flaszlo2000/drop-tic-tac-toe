/**
	@author Tamara Süli
	@author Levente Löffler
	@version 1.0.7 6/16/2020

*/


#pragma once
#include "data.h"

void ai_turn(game_data* data, char* step, unsigned char round);

void player_turn(char* step, unsigned char round);

int check_step(map_data* map, char* step);

void step_input(game_data* data, char* step, unsigned char round);

void step_perform(map_data* data, char* step, unsigned char round);

void turn(game_data* data, unsigned char round);