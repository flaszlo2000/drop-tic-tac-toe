/**
	@author Fazekas László
	@version 1.0.0 6/18/2020

	Implementation of ai.
*/

#include "ai.h"
#include <stdio.h>

void test(map_data * map, unsigned short round) {
    unsigned short user_id = round % 2;

    for(int i=0; i < map->x; i++) {
        for(int j=0; j < map->y; j++) {
            if(map->pMap[i][j] == 1) {
                printf("a\n");
                break;
            } else {
                printf("b\n");
            }
        }

        printf("\n");
    }
}