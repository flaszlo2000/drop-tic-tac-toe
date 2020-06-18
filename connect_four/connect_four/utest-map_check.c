/**
    @author Tamara Süli
    @version 1.0.0 6/18/2020
*/

#include "map_check.h"
#include "utest-map_check.h"

#include "CUnit.h" //#include <CUnit/CUnit.h>

static void test_check_draw() {}

static void test_check_win() {}



CU_TestInfo map_check_tests[] = {
    {"draw",           test_check_draw},
    {"win",            test_check_win},
    CU_TEST_INFO_NULL
};