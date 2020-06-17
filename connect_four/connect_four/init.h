/**
	@author Levente Löffler
	@version 1.1.6 6/17/2020

	This module handles the data structure initializations and uninitializations.
*/

#ifndef INIT_H
#define INIT_H

#include "data.h"

void init(game_data* game);
void reset(map_data* map);
void uninit(game_data* game);

#endif