/**
	@author Tamara S�li
	@author Levente L�ffler
	@author Fazekas László
	@version 1.0.11 6/18/2020

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