/**
    @author Tamara Süli
    @version 1.1.0 6/19/2020
*/
#include "display.h"
#include "utest-display.h"

#include <CUnit/CUnit.h>
#include <string.h>

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

static void test_display() {
	map_data data = initMap(2, 2, '0');

       char buffer[BUFSIZ];
        setbuf(stdout, buffer);
        for(int i = 0; i < BUFSIZ; i++)
            buffer[i] = 0;
        
        display(&data);

        setbuf(stdout, NULL);

        CU_ASSERT_STRING_EQUAL(buffer, "\nA B\n   \n0 0\n0 0\n\n--------------------\n")


    for(int i = 0; i < data.x; i++)
        free(data.pMap[i]);

    free(data.pMap); 
}



CU_TestInfo display_tests[] = {
    {"display",           test_display},
    CU_TEST_INFO_NULL
};