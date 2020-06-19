/**
    @author Tamara Süli
    @version 1.0.0 6/18/2020
*/

#include "init.h"
#include "utest-init.h"

#include "CUnit.h" //#include <CUnit/CUnit.h>

map_data initMap(unsigned char x, unsigned char y, unsigned char value) {
    map_data mData = { x, y, NULL };
    for (unsigned char c = 0; c < mData.x; c++)
        for (unsigned char d = 0; d < mData.y; d++)
            mData.pMap[c][d] = value;
    return mData;
}

static void test_init() {
 
}

static void test_reset() {
    map_data data = initMap('5', '5', '2');
    reset(&data);
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            CU_ASSERT_EQUAL(data.pMap[i][j], '0');
}

static void test_uninit() {
    game_data game;
   
    init(&game);

    uninit(&game);

    CU_ASSERT_PTR_NULL(game.pP1->sName);
    CU_ASSERT_PTR_NULL(game.pP2->sName);
    CU_ASSERT_PTR_NULL(game.pP1);
    CU_ASSERT_PTR_NULL(game.pP2);
}


CU_TestInfo init_tests[] = {
    {"init",           test_init},
    {"reset",          test_reset},
    {"uninit",         test_uninit},
    CU_TEST_INFO_NULL
};