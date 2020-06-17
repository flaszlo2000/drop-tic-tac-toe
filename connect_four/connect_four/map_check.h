/**
	@author Levente Löffler
	@version 1.0.0 6/14/2020

	This module provides function to iterate over the map and check for wins and draws.
*/

#ifndef MAP_CHECK_H
#define MAP_CHECK_H

#include "data.h"
#include <stdbool.h>

bool check_draw(map_data* sMap);
bool check_win(game_data* sGame, unsigned short nTurn);

#endif