/**
    @author Tamara Süli
    @version 1.1.0 6/19/2020
*/

#include "init.h"
#include "utest-init.h"

#include <CUnit/CUnit.h>

#include <malloc.h>
#include <stdio.h>
#include <string.h>

map_data initMap(unsigned char x, unsigned char y, unsigned char value) {

    map_data mData = { x, y, malloc(x * sizeof(unsigned char*))};
    for (unsigned char c = 0; c < mData.x; c++){
        mData.pMap[c] = malloc(y* sizeof(unsigned char));
        for (unsigned char d = 0; d < mData.y; d++)
            mData.pMap[c][d] = value;
    }
    return mData;
}


static void test_reset() {
    map_data data = initMap('5', '5', '2');
    reset(&data);
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            CU_ASSERT_EQUAL(data.pMap[i][j], '0');

    for(int i = 0; i < data.x; i++)
        free(data.pMap[i]);

    free(data.pMap);
}


CU_TestInfo init_tests[] = {
    {"reset",          test_reset},
    CU_TEST_INFO_NULL
};