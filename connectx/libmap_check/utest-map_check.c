/**
    @author Tamara Süli
    @version 1.1.0 6/19/2020
*/

#include "map_check.h"
#include "utest-map_check.h"

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

static void test_check_draw() {
    map_data data = initMap(2, 2, 2);

    CU_ASSERT_TRUE(check_draw(&data));

    data.pMap[0][0] = '0';

    CU_ASSERT_FALSE(check_draw(&data));

    for(int i = 0; i < data.x; i++)
        free(data.pMap[i]);

    free(data.pMap);
}

static void test_check_win() {
    game_data game = {1, 2, NULL, NULL, initMap(2, 2, '0')};

    game.map.pMap[1][0] = '1';
    game.map.pMap[1][1] = '1';

    CU_ASSERT_TRUE(check_win(&game, 3));

    game.map.pMap[1][0] = '0';
    game.map.pMap[1][1] = '0';



    game.map.pMap[0][1] = '1';
    game.map.pMap[1][0] = '1';

    CU_ASSERT_TRUE(check_win(&game, 3));

    game.map.pMap[0][1] = '0';
    game.map.pMap[1][0] = '0';



    game.map.pMap[0][1] = '1';
    game.map.pMap[1][0] = '2';

    CU_ASSERT_FALSE(check_win(&game, 2));


    for(int i = 0; i < game.map.x; i++)
        free(game.map.pMap[i]);

    free(game.map.pMap);
}



CU_TestInfo map_check_tests[] = {
    {"draw",           test_check_draw},
    {"win",            test_check_win},
    CU_TEST_INFO_NULL
};