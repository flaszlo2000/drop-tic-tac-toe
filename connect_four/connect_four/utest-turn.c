/**
    @author Tamara Süli
    @version 1.0.0 6/18/2020
*/

#include "turn.h"
#include "utest-turn.h"

#include "CUnit.h" //#include <CUnit/CUnit.h>


map_data initMap(unsigned char x, unsigned char y, unsigned char value) {
    map_data mData = { x, y, NULL };
    for (unsigned char c = 0; c < mData.x; c++)
        for (unsigned char d = 0; d < mData.y; d++)
            mData.pMap[c][d] = value;
    return mData;
}

static void test_check_step() {
    map_data data = initMap(2, 2, 0);
    char num = '2';
    char upCase = 'a';
    char lowCase = 'A';

    CU_ASSERT_EQUAL(check_step(&data, &num), 0);
    CU_ASSERT_EQUAL(check_step(&data, &upCase), 1);
    CU_ASSERT_EQUAL(check_step(&data, &lowCase), 1);

}

static void test_step_perform() {
    map_data data = initMap('2', '2', '0');
    step_perform(&data, 'a', 1);
    step_perform(&data, 'b', 2);

    CU_ASSERT_EQUAL(data.pMap[1][0], '1');
    CU_ASSERT_EQUAL(data.pMap[1][1], '2');

}



CU_TestInfo turn_tests[] = {
    {"check step",   test_check_step},
    {"step perform", test_step_perform},
    CU_TEST_INFO_NULL
};