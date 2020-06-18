/**
	@author Fazekas László
	@version 1.0.0 6/18/2020

	Implementation of ai.
*/

#include "ai.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char get_char_from_int(int char_in_int_format) {
    return (97 + char_in_int_format);
}

int get_user_point_count(map_data * map, unsigned short needed_number) {
    int c = 0;

    for(int i=0; i < map->x; i++) {
        for(int j=0; j < map->y; j++) {
            if(map->pMap[i][j] == needed_number + '0') {
                c++;
            }
        }
    }

    return c;
}

int random_move(int to) {
    srand(time(NULL));

    return (rand() % to);
}

char ai_main(map_data * map, unsigned short round) {
    char result;
    unsigned short user_id = round % 2;

    if(round == 1) {
        // if the ai have to start, then that will choose a random start pos
        result = get_char_from_int(random_move(map->x));
    } else {
        int current_point_count = get_user_point_count(map, user_id+1);
        
        if(current_point_count > 0) {
            // atm both has at least a point on the map
            result = 'b'; // TODO
        } else {
            result = get_char_from_int(random_move(map->x));
        }
    }

    return result;
}

/*
NOTE:
    map's pMap is a char based two dimensional array
    map's x and y are numbers

    round starts with 1

*/