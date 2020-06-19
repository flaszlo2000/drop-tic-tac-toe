/**
	@author Tamara Süli
	@author Levente Löffler
	@version 1.0.10 6/17/2020

*/


#ifndef TURN_H
#define TURN_H

#include "data.h"

void turn(game_data* data, unsigned short round);

char step_input(game_data* data, unsigned short round);

void step_perform(map_data* data, char step, unsigned short round);

char ai_turn(map_data* map, char* sName, unsigned short round, unsigned char goal);

char player_turn(map_data* map, char* sName, unsigned short round, unsigned char goal);

int check_step(map_data* map, char* step);

#endif