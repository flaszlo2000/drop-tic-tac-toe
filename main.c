#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

#define TABLE_X 8
#define TABLE_Y 8

int table[TABLE_X][TABLE_Y];

void make_correct_line() {
    for(int i=0; i<TABLE_X*2-1; i++) { printf("-"); }
    printf("\n");
}

void show_options() {
    char column_i = 97; // a
    for(int i=0; i<TABLE_X; i++){
        printf("%c", column_i + i);

        if(i+1 < TABLE_X){ printf(" "); }
    }
    printf("\n");
}

void show_main_table() {
    printf("\n");
    show_options();
    make_correct_line();

    for(int i=0; i<TABLE_X; i++) {
        for(int j=0; j<TABLE_Y; j++) {
            printf("%d", table[i][j]);

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

bool change_table(int user_number, char user_choice) {
    bool result = false;

    if(user_choice >= 97 && user_choice < 97 + TABLE_X) {
        int column = (int)user_choice - 97;
        printf("column: %d\n", column);
        // bc the gravity works here as well
        for(int i=TABLE_Y - 1; i >= 0; i--) {
            if(table[i][column] == 0) {
                table[i][column] = ++user_number; // at here, we can use this form
                break;
            }
        }


        result = true;
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
        if(!change_table(user_number, user_choice)){
            last_fail = true;
            user_number = 1 - user_number; // give an other try
            printf("[*] ERROR: incorrect char\n");
        } else {
            if(last_fail){
                last_fail = false;
            }
        }
    }
}

int main() {
    set_default_the_main_table();
    game_loop();
    return 0;
}