/**
	@author Levente Löffler
	@version 1.0.0 6/14/2020
*/

#pragma once
#include "data.h"
#include <stdbool.h>

bool check_draw(map_data* sMap);
bool check_win(map_data* sGame, char nRound);