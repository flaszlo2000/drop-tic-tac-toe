/**
	@author Fazekas László
	@version 1.0.0 6/18/2020

	Implementation of ai.
*/

#include "ai.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

char get_char_from_int(int char_in_int_format) {
    return (97 + char_in_int_format);
}

struct point {
    int x;
    int y;
};

int get_user_point_count(map_data * map, unsigned short needed_number) {
    int c = 0;

    for(int i=0; i < map->x; i++) {
        for(int j=0; j < map->y; j++) {
            if(map->pMap[i][j] == needed_number + '0') {
                c++;
            }
        }
    }

    printf("count: %d\n", c);

    return c;
}

int random_move(int to) {
    return (rand() % to);
}

bool empty_pos(map_data * map, int x, int y) {
    bool result = false;
    
    if(map->pMap[x][y] == '0') { result = true; };

    return result;
}

char ai_main(map_data * map, unsigned short round) {
    char result;

    unsigned short user_id = round % 2;
    int current_point_count = get_user_point_count(map, user_id+1);
    
    if(current_point_count > 0) {
        // atm both has at least a point on the map
        result = get_char_from_int(random_move(map->x)); // TODO
    } else {
        int random_start_pos;
        
        while(true) {
            random_start_pos = random_move(map->x);
            if(empty_pos(map, map->y-1, random_start_pos)) { break; }
        }

        result = get_char_from_int(random_start_pos);
    }

    return result;
}

/*
NOTE:
    map's pMap is a char based two dimensional array
    map's x and y are numbers

    round starts with 1

*/