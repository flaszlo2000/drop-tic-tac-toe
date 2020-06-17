/**
	@author Levente Löffler
	@version 1.1.5 6/17/2020

	This module handles the data structure initializations and uninitializations.
*/

#pragma once
#include "data.h"

void init(game_data* game);
void reset(map_data* map);
void uninit(game_data* game);