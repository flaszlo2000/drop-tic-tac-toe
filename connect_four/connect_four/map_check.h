/**
	@author Levente L�ffler
	@version 1.0.0 6/14/2020

	This module provides function to iterate over the map and check for wins and draws.
*/

#pragma once
#include "data.h"
#include <stdbool.h>

bool check_draw(map_data* sMap);
bool check_win(map_data* sMap, char nTurn);