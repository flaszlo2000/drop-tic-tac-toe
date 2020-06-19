/**
    @author Tamara Süli
    @version 1.0.0 6/18/2020
*/

#include "map_check.h"
#include "utest-map_check.h"

#include <CUnit/CUnit.h>

map_data initMap(unsigned char x, unsigned char y, unsigned char value) {
    map_data mData = { x, y, NULL };
    for (unsigned char c = 0; c < mData.x; c++)
        for (unsigned char d = 0; d < mData.y; d++)
            mData.pMap[c][d] = value;
    return mData;
}

static void test_check_draw() {
    map_data data = initMap(2, 2, 2);

    CU_ASSERT_TRUE(check_draw(&data));

    data.pMap[0][0] = '0';

    CU_ASSERT_FALSE(check_draw(&data));
}

static void test_check_win() {}



CU_TestInfo map_check_tests[] = {
    {"draw",           test_check_draw},
    {"win",            test_check_win},
    CU_TEST_INFO_NULL
};