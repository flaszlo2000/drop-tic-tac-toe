/**
	@author Tamara Süli
	@author Levente Löffler
	@author Fazekas László
	@version 1.4.0 6/19/2020
	Implementation of the turn module.
*/

#include "turn.h"
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
    int result = (rand() % to );
    return result;
}

bool empty_pos(map_data * map, int x, int y) {
    bool result = false;
    
    if(map->pMap[x][y] == '0') { result = true; };

    return result;
}

char get_winning_opportunity(map_data * map, int needed_char, unsigned char goal) {
    int c = 0; // this will contain the symbol count in a line (only for |)
    int zero_counter = 0; // this will count the amount of zeros in a sequence
    int zero_pos = 0; // this will contant the place where the zero is

    // check from the left-bottom corner
    for(int i=map->x - 1; i >= 0; i--) {
        for(int j=0; j < map->y ; j++) {
            if(map->pMap[i][j] == needed_char + '0') {
                c = 1; // reset the counter

                // check | (up)
                for(int k=i; k >= 0; k--) {
                    // count how many symbols do we have in a line
                    if(map->pMap[k][j] == needed_char + '0') {
                        c++;

                        if(c == goal) {
                            if(i - goal+1 < 0) { // if this is on the top
                                c = 0;
                            }
                        }
                    } else {
                        if(map->pMap[k][j] != 0 + '0') {
                            // if an other player owns the next place
                            c = 0;
                        }
                        
                        break;
                    }
                }
                if(c == goal) { return get_char_from_int(j); }
            }

            // with theese methods we have a gap filler methos as well 

            // check -- (right)
            if(j+goal-1 < map->y) {
                zero_counter = 0;

                for(int k=0; k < goal; k++) {
                    if(map->pMap[i][j+k] != needed_char + '0') {
                        if(map->pMap[i][j+k] == 0 + '0') {
                            if(i+1 < map->x) {
                                if(map->pMap[i+1][j+k] != 0 + '0') {
                                    zero_pos = j + k;
                                    zero_counter++;
                                } else {
                                    zero_counter = 0;
                                    break;
                                }
                            } else {
                                zero_pos = j+k;
                                zero_counter++;
                            }
                        } else {
                            zero_counter = 0;
                            break;
                        }
                    }
                }

                if(zero_counter == 1) {
                    c = goal;
                }
            }
            if(c == goal) {
                return get_char_from_int(zero_pos);
            }

            zero_pos = 0;
            // check / (up-right)
            if(i-goal+1 >= 0 && j+goal-1 < map->y) {
                zero_counter = 0;
                
                for(int k=0; k < goal; k++) {
                    if(map->pMap[i-k][j+k] != needed_char + '0') {
                        if(map->pMap[i-k][j+k] == 0 + '0') { // if the number is 0, this is good, and we save thats position (but we will let only one from them to exist)
                            if(k > 0) {
                                if(map->pMap[i-k+1][j+k] == 0 + '0') {
                                    zero_counter = 0;
                                    break;
                                } else { // if there is not void underneath the chosen number
                                    zero_pos = j+k;
                                    zero_counter++;
                                }
                            }
                        } else { // or if it is not zero, this means this is already taken for an other user
                            zero_counter = 0;
                            break; // with this situation, we dont need to continue the investigating
                        }
                    }
                }

                if(zero_counter == 1) { // we want to see only one zero! and that could be anywhere in the sequence (so this is why we saved that position)
                    c = goal;
                }
            }

            if(c == goal) {
                return get_char_from_int(zero_pos);
            }

            
            zero_pos = 0;
            // check \e
            if(i-goal+1 >= 0 && j-goal+1 >= 0) {
                for(int k=0; k < goal; k++) {
                    if(map->pMap[i-k][j-k] != needed_char + '0') {
                        if(map->pMap[i-k][j-k] == 0 + '0') { // if the number is 0, this is good, and we save thats position (but we will let only one from them to exist)
                            if(k > 0) {
                                if(map->pMap[i-k+1][j-k] == 0 + '0') {
                                    zero_counter = 0;
                                    break;
                                } else { // if there is not void underneath the chosen number
                                    zero_pos = j-k;
                                    zero_counter++;
                                }
                            } else {
                                zero_pos = j-k;
                                zero_counter++;
                            }
                        } else { // or if it is not zero, this means this is already taken for an other user
                            zero_counter = 0;
                            break; // with this situation, we dont need to continue the investigating
                        }
                    }
                }

                if(zero_counter == 1) { // we want to see only one zero! and that could be anywhere in the sequence (so this is why we saved that position)
                    c = goal;
                }
            }

            if(c == goal) {
                return get_char_from_int(zero_pos);
            }

        }
    }

    return '0';
}

char ai_main(map_data * map, unsigned short round, unsigned char goal) {
    char result;
    int random_start_pos;

    int loop_c = 0;

    unsigned short user_id = (round + 1) % 2;
    int current_point_count = get_user_point_count(map, user_id+1);
    
    if(current_point_count > 0) {
        while(true) {
            if(loop_c > 20) {
                printf("The table is full!\n");
                return '0';
            }
            // atm both has at least a point on the map

            // check for win positions
            char win_option = get_winning_opportunity(map, user_id+1, goal);
            //printf("win option: %c\n", win_option);

            if(win_option != '0') {
                return win_option;
            }

            // check for win positions for the enemy
            win_option = get_winning_opportunity(map, 1-user_id+1, goal);
            //printf("kill streak option: %c\n", win_option);

            if(win_option != '0') {
                return win_option;
            }

            // if there is no win position neither for the ai and the user, than make a point what has benefits for the ai
            // follow its longest line or if that is not completeable then start a new random point

            random_start_pos = random_move(map->y); // here this is not start pos
            if(empty_pos(map, 0, random_start_pos)) { break; }

            loop_c++;
        }

        result = get_char_from_int(random_start_pos);

    } else {
        while(true) { // refactor this
            random_start_pos = random_move(map->y);
            if(empty_pos(map, map->x-1, random_start_pos)) { break; }
        }

        result = get_char_from_int(random_start_pos);
    }

    return result;
}


char ai_turn(map_data* map, char* sName, unsigned short round, unsigned char goal) {
	printf("%s making its turn now: ", sName);
	char result = ai_main(map, round, goal);

	printf("%c\n", result);
	return result;
}



char player_turn(map_data* map, char* sName, unsigned short round, unsigned char goal) { // atm goal args is unused bc the givel data structure is not compatible
	char step;

	printf("%s, make your move: ", sName);

	while (1)
	{
		scanf("\n%c", &step);
		if (check_step(map, &step))
			return step;
	}
}



char step_input(game_data* data, unsigned short round) {
	printf("This is the %hu. turn.\n", round);

	if(round % 2) {
		return data->pP1->fTurn(&data->map, data->pP1->sName, round, data->lLength);
	} else {
		return data->pP2->fTurn(&data->map, data->pP2->sName, round, data->lLength);
	}
}



void step_perform(map_data* map, char step, unsigned short round) {
	unsigned char ch = round % 2 ? '1' : '2';

	for (int i = map->x - 1; i >= 0; i--) {
		if (map->pMap[i][step - 'A'] == '0') {
			map->pMap[i][step - 'A'] = ch;
			break;
		}
	}
}



int check_step(map_data* map, char* step) {
	char temp = getchar();
	while (temp != '\n')
	{
		temp = getchar();
		if (temp == '\n')
		{
			printf("Too many characters. Please retry: ");
			return 0;
		}	
	}

	if ((*step < 'A' || *step >= map->y + 'A') && (*step < 'a' || *step >= map->y + 'a'))
	{
		printf("Incorrect column. Please retry: ");
		return 0;
	}

	if (*step >= 'a' && *step < map->y + 'a')
		*step -= 'a' - 'A';

	if (map->pMap[0][*step - 'A'] == '0')
		return 1;

	printf("The column is full. Please retry: ");
	return 0;
}



void turn(game_data* data, unsigned short round) {
	step_perform(&data->map, step_input(data, round), round);
}