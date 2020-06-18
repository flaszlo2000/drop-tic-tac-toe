/**
    @author Tamara Süli
    @version 1.0.0 6/18/2020
*/

#include "init.h"
#include "utest-init.h"

#include "CUnit.h" //#include <CUnit/CUnit.h>

static void test_init() {}

static void test_reset() {}

static void test_uninit() {}


CU_TestInfo init_tests[] = {
    {"init",           test_init},
    {"reset",          test_reset},
    {"uninit",         test_uninit},
    CU_TEST_INFO_NULL
};