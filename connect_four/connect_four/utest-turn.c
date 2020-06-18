/**
    @author Tamara Süli
    @version 1.0.0 6/18/2020
*/

#include "turn.h"
#include "utest-turn.h"

#include "CUnit.h" //#include <CUnit/CUnit.h>

static void test_ai_turn() {}

static void test_player_turn() {}

static void test_step_input() {}

static void test_check_step() {}

static void test_step_perform() {}

static void test_turn() {}



CU_TestInfo turn_tests[] = {
    {"ai",           test_ai_turn},
    {"player",       test_player_turn},
    {"step input",   test_step_input},
    {"check step",   test_check_step},
    {"step perform", test_step_perform},
    {"turn",         test_turn},
    CU_TEST_INFO_NULL
};