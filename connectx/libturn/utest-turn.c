/**
    @author Tamara Süli
    @version 1.1.0 6/19/2020
*/

#include "turn.h"
#include "utest-turn.h"

#include <CUnit/CUnit.h>

#include <malloc.h>


map_data initMap(unsigned char x, unsigned char y, unsigned char value) {

    map_data mData = { x, y, malloc(x * sizeof(unsigned char*))};
    for (unsigned char c = 0; c < mData.x; c++){
        mData.pMap[c] = malloc(y* sizeof(unsigned char));
        for (unsigned char d = 0; d < mData.y; d++)
            mData.pMap[c][d] = value;
    }
    return mData;
}

char tmp(map_data* data, char* param, unsigned short num, unsigned char goal) {
    return 'a';
}

static void test_turn() {
    game_data game;
    game.nWins = 1;
    game.lLength = 2;

    game.pP1 = malloc(sizeof(player_data));
    game.pP1->sName = "Béla";
    game.pP1->fTurn = &tmp;
    game.pP1->cWins = 0;

    game.pP2 = malloc(sizeof(player_data));
    game.pP2->sName = "Józsi";
    game.pP2->fTurn = &tmp;
    game.pP2->cWins = 0;

    game.map = initMap(2, 2, '0');

    ungetc('\n', stdin);
    turn(&game, 1);

    CU_ASSERT_EQUAL(game.map.pMap[1][0], '1');


    free(game.pP1);
    free(game.pP2);

    for(int i = 0; i < game.map.x; i++)
        free(game.map.pMap[i]);

    free(game.map.pMap);
}



static void test_check_step() {
    map_data data = initMap(2, 2,'0');
    char num = '2';
    char upCase = 'a';
    char lowCase = 'A';

    ungetc('\n', stdin);
    CU_ASSERT_EQUAL(check_step(&data, &num), 0);
    ungetc('\n', stdin);
    CU_ASSERT_EQUAL(check_step(&data, &upCase), 1);
    ungetc('\n', stdin);
    CU_ASSERT_EQUAL(check_step(&data, &lowCase), 1); 

    for(int i = 0; i < data.x; i++)
        free(data.pMap[i]);

    free(data.pMap); 

}

static void test_step_perform() {
    map_data data = initMap(2, 2, '0');
    step_perform(&data, 'A', 1);
    step_perform(&data, 'B', 2);

 
    CU_ASSERT_EQUAL(data.pMap[1][0], '1');
    CU_ASSERT_EQUAL(data.pMap[1][1], '2');

    for(int i = 0; i < data.x; i++)
        free(data.pMap[i]);

    free(data.pMap);

}

static void test_ai_turn() {
    map_data data = initMap(2, 2, '0');
    map_data data2 = initMap(3, 3, '0');


    CU_ASSERT_EQUAL(ai_turn(&data, "Bela", 1, 2), 'B');
    CU_ASSERT_EQUAL(ai_turn(&data2, "Bela", 1, 3), 'B');

    for(int i = 0; i < data.x; i++) {
        free(data.pMap[i]);
        free(data2.pMap[i]);
    }

    free(data.pMap);
    free(data2.pMap); 

}

static void test_player_turn() {
    map_data data = initMap(2, 2, '0');

    ungetc('A', stdin);
    CU_ASSERT_EQUAL(player_turn(&data, "Bela", 1, 2), 'A');

    for(int i = 0; i < data.x; i++)
        free(data.pMap[i]);
    
    free(data.pMap); 

}


CU_TestInfo turn_tests[] = {
    {"turn",         test_turn},
    {"check step",   test_check_step},
    {"step perform", test_step_perform},
    {"ai",           test_ai_turn},
    {"player",       test_player_turn},
    CU_TEST_INFO_NULL
};