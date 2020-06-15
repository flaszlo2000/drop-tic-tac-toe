/**
	@author Levente L�ffler
	@version 1.1.0 6/15/2020

	This module handles the data structure initializations and uninitializations.
*/

#pragma once
#include "data.h"

void init(game_data* game);
void reset(map_data* map);
void uninit(map_data* map);