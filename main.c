#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TABLE_X 8
#define TABLE_Y 8
#define REQUIRED_LINE_LEN 4

typedef struct Dictionary {
    char * function_name;
    void (*func_ptr)(void);
} dict;

int table[TABLE_X][TABLE_Y];

struct win_point {
    int x;
    int y;
    char with;
};

bool turn_end = false;
struct win_point win_point_start;
struct win_point win_points[REQUIRED_LINE_LEN];

void make_correct_line() {
    for(int i=0; i<TABLE_X*2-1; i++) { printf("-"); }
    printf("\n");
}

void show_options() {
    char column_i = 97; // a
    for(int i=0; i<TABLE_X; i++) {
        if(table[0][i] == 0) {
            printf("%c", column_i + i);

            if(i+1 < TABLE_X){ printf(" "); }
        } else {
            printf("  ");
        }
    }
    printf("\n");
}

void make_final_points() {
    win_points[0] = win_point_start;
    int point_index = 0;
    int from;

    switch(win_point_start.with) {
        case '-':
            from = win_point_start.x;
            for(int i=from; i<from+REQUIRED_LINE_LEN; i++) {
                win_points[point_index].x = i;
                win_points[point_index].y = win_point_start.y;

                point_index++;
            }
            break;

        case '|':
            from = win_point_start.y;
            for(int i=from; i>from-REQUIRED_LINE_LEN; i--) {
                win_points[point_index].x = win_point_start.x;
                win_points[point_index].y = i;

                point_index++;
            }
            break;

        case '/':
            for(int i=0; i<REQUIRED_LINE_LEN; i++) {
                win_points[point_index].x = win_point_start.x + i;
                win_points[point_index].y = win_point_start.y - i;

                point_index++;
            }
            break;

        case '\\':
            for(int i=0; i<REQUIRED_LINE_LEN; i++) {
                win_points[point_index].x = win_point_start.x - i;
                win_points[point_index].y = win_point_start.y - i;

                point_index++;
            }
            break;
    }
}

bool not_in_finals(int x, int y) {
    bool result = true;

    for(int i=0; i<REQUIRED_LINE_LEN; i++) {
        if(win_points[i].x == x && win_points[i].y == y) {
            result = false;
            break;
        }
    }

    return result;
}

void clear_by_os_type() {
    #ifdef __linux__
        system("clear");
    #elif _WIN32
        printf("win shell clear TODO\n");
        printf("\n");
    #endif
}

void show_main_table() {
    clear_by_os_type();
    show_options();
    make_correct_line();

    for(int i=0; i<TABLE_X; i++) {
        for(int j=0; j<TABLE_Y; j++) {
            if(turn_end) {
                if(not_in_finals(j, i)) {
                    printf("%d", table[i][j]);
                } else {
                    printf("%c", win_point_start.with);
                }
            } else {
                printf("%d", table[i][j]);
            }

            if(j+1 < TABLE_Y){ printf(" "); }
        }
        printf("\n");
    }

    make_correct_line();
    show_options();
}

void set_default_the_main_table() {
    for(int i=0; i<TABLE_X; i++) {
        for(int j=0; j<TABLE_Y; j++) {
            table[i][j] = 0;
        }
    }
}

char get_data_from_user() {
    // a safe way to get only one first char and dont get overflow
    unsigned int allocated_mul = 128;
    unsigned int index_in_str = 0;
    char * user_input = malloc(sizeof(char) * allocated_mul);

    unsigned int ch = 0;
    while((ch = getchar()) != '\n' && ch != EOF) {
        user_input[index_in_str++] = (char)ch;

        if(index_in_str == allocated_mul) {
            allocated_mul *= 2;
            user_input = realloc(user_input, allocated_mul);
        }
    }

    char result = user_input[0];
    free(user_input);

    return result;
}

bool check_for_win(int player_number) {
    bool win = false;

    for(int j=TABLE_Y - 1; j >= 0; j--) {
        for(int i=0; i<TABLE_X; i++) {
            // |
            if(j-REQUIRED_LINE_LEN+1 >= 0) {
                for(int k=0; k<REQUIRED_LINE_LEN; k++) {
                    if(table[j-k][i] != player_number) {
                        break;
                    } else {
                        if(k+1 >= REQUIRED_LINE_LEN) {
                            win_point_start.with = '|';
                            win = true;
                        }
                    }
                }
            }

            // --
            if(i+REQUIRED_LINE_LEN-1 < TABLE_X) {
                for(int k=0; k<REQUIRED_LINE_LEN; k++) {
                    if(table[j][i+k] != player_number) {
                        break;
                    } else {
                        if(k+1 >= REQUIRED_LINE_LEN) {
                            win_point_start.with = '-';
                            win = true;
                        }
                    }
                }
            }

            // /
            if(i+REQUIRED_LINE_LEN-1 < TABLE_X && j-REQUIRED_LINE_LEN+1 >= 0) {
                for(int k=0; k<REQUIRED_LINE_LEN; k++) {
                    if(table[j-k][i+k] != player_number) {
                        break;
                    } else {
                        if(k+1 >= REQUIRED_LINE_LEN) {
                            win_point_start.with = '/';
                            win = true;
                        }
                    }
                }
            }

            //  \e (here the e is an "escape char")
            if(i-REQUIRED_LINE_LEN+1 >= 0 && j-REQUIRED_LINE_LEN+1 >= 0) {
                for(int k=0; k<REQUIRED_LINE_LEN; k++) {
                    if(table[j-k][i-k] != player_number) {
                        break;
                    } else {
                        if(k+1 >= REQUIRED_LINE_LEN) {
                            win_point_start.with = '\\';
                            win = true;
                        }
                    }
                }
            }

            if(win) {
                win_point_start.x = i;
                win_point_start.y = j;
                break;
            }
        }
        if(win) { break; }
    }

    return win;
}

bool change_table(int user_number, char user_choice) {
    bool result = false;

    if(user_choice >= 97 && user_choice < 97 + TABLE_X) {
        int column = (int)user_choice - 97;
        
        if(table[0][column] == 0) {
            // bc the gravity works here as well
            for(int i=TABLE_Y - 1; i >= 0; i--) {
                if(table[i][column] == 0) {
                    table[i][column] = ++user_number;
                    break;
                }
            }

            result = true;
        }
    }

    return result;
}

void game_loop() {
    char user_choice;
    int user_number = 1;
    // 0 == user_1, 1 == user_2

    bool last_fail = false;

    while(true) {
        user_number = 1 - user_number; // change the users

        if(!last_fail) { show_main_table(); }

        printf("[user %d]: ", user_number + 1);
        user_choice = get_data_from_user();
        if(!change_table(user_number, user_choice)) {
            if(!last_fail) { last_fail = true; }

            user_number = 1 - user_number; // give an other try
            printf("[*] ERROR: incorrect char\n");
        } else {
            if(last_fail){
                last_fail = false;
            }

            if(check_for_win(user_number+1)) {
                turn_end = true;
                make_final_points();
                show_main_table();
                printf("user %d won!\n", user_number + 1);
                break;
            }
        }
    }
}

void print_normal_game_options(dict function_map[], int len) {
    for(int i=0; i<len; i++) {
        printf("\t%d) %s\n", i+1, function_map[i].function_name + '\0');
    }
}

void print_game_options(dict function_map[], int len) {
    // this is a wrapper for normal game options
    print_normal_game_options(function_map, len);
    printf("\t%d) N round competition\n", len + 1);
}

void menu() {
    dict function_map[] = {{"User vs User", &game_loop},
                           {"User vs Computer", NULL},
                           {"Computer vs Computer", NULL}};

    int function_count = sizeof(function_map)/sizeof(dict);
    int user_choice = 0;
    char raw_data_from_user;

    printf("Please select a game mode: \n");
    print_game_options(function_map, function_count);
    
    while(true) {
        printf("Choice: ");
        raw_data_from_user = get_data_from_user();
        if(raw_data_from_user >= 48 && raw_data_from_user <= 57) {
            user_choice = (raw_data_from_user - '0') - 1; // set back the value in "index form"

            if(user_choice >= 0 && user_choice <= function_count) {
                if(user_choice == function_count) {
                    printf("n round comp\n");
                } else {
                    function_map[user_choice].func_ptr();
                    break;
                }
            } else {
                printf("[*] ERROR: incorrect option!\n");
            }
        } else {
            printf("[*] ERROR: this is not a number!\n");
        }
    }   
}

int main() {
    set_default_the_main_table();
    menu();

    //if(REQUIRED_LINE_LEN < TABLE_X && REQUIRED_LINE_LEN < TABLE_Y) {
    //   game_loop();
    //} else {
    //    printf("[*] ERROR: this competition is not completable\n");
    //}
    return 0;
}