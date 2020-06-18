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
    return (65 + char_in_int_format);
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
    return (rand() % to);
}

bool empty_pos(map_data * map, int x, int y) {
    bool result = false;
    
    if(map->pMap[x][y] == '0') { result = true; };

    return result;
}

char get_winning_opportunity(map_data * map, int needed_char, unsigned char goal) {
    printf("given id: %d\n", needed_char);
    int c = 0; // this will contain the symbol count in a line
    int zero_counter = 0;
    int zero_pos = 0;

    // check from the left-bottom corner
    for(int i=map->x - 1; i >= 0; i--) {
        for(int j=0; j < map->y ; j++) {
            if(map->pMap[i][j] == needed_char + '0') {
                c = 1; // reset the counter

                // check | (atm upvards)
                for(int k=i; k >= 0; k--) {
                    // count how many symbols do we have in a line
                    if(map->pMap[k][j] == needed_char + '0') {
                        c++;
                    } else {
                        if(map->pMap[k][j] != 0 + '0') {
                            // if an other player owns the next place
                            c = 0;
                        }
                        
                        break;
                    }
                }
                if(c == goal) { return get_char_from_int(j); }

                c = 1;
                // check ->
                for(int k=j; k < map->y; k++) {
                    zero_counter = 0;

                    if(k+goal-1 < map->y) {  // we take goal amount of elements, atm we know nothing about theese numbers
                        for(int l=k; l < k+goal; l++) {
                            if(map->pMap[i][l] != needed_char + '0') { // if the current number is not eq what we would like to see, we have only two options
                                if(map->pMap[i][l] == 0 + '0') { // if the number is 0, this is good, and we save thats position (but we will let only one from them to exist)
                                    zero_pos = l;
                                    zero_counter++;
                                } else { // or if it is not zero, this means this is already taken for an other user
                                    zero_counter = 0;
                                    break; // with this situation, we dont need to continue the investigating
                                }
                            }
                        }

                        if(zero_counter == 1) { // we want to see only one zero! and that could be anywhere in the sequence (so this is why we saved that position)
                            c = goal;
                            break;
                        }
                    } else { // what if we dont have enough place for the invesigation
                        break;
                    }
                }

                if(c == goal) {
                    return get_char_from_int(zero_pos);
                }

                c = 1;
                // check /

                
            }
        }
    }

    return '0';
}

char ai_main(map_data * map, unsigned short round, unsigned char goal) {
    char result;
    
    printf("from ai > goal: %hhu\n", goal);

    unsigned short user_id = (round + 1) % 2;
    int current_point_count = get_user_point_count(map, user_id+1);
    
    if(current_point_count > 0) {
        // atm both has at least a point on the map

        // check for win positions
        char win_option = get_winning_opportunity(map, user_id+1, goal);
        printf("win option: %c\n", win_option);

        if(win_option != '0') {
            return win_option;
        }

        // check for win positions for the enemy

        // if there is no win position nether for the ai and the user, than make a point what has benefits for the ai
        // follow its longest line or if that is not completeable then start a new random point

        result = get_char_from_int(random_move(map->x));

    } else {
        int random_start_pos;
        
        while(true) { // refactor this
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