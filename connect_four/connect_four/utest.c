/**
    @author Tamara Süli
    @version 1.0.0 6/18/2020
*/

#include "display.h"
#include "turn.h"
#include "init.h"
#include "map_check.h"
#include "data.h"

#include "utest-display.h"
#include "utest-turn.h"
#include "utest-init.h"
#include "utest-map_check.h"

#include "Basic.h"  // #include <CUnit/Basic.h>
#include "CUnit.h"  // #include <CUnit/CUnit.h>

CU_SuiteInfo tic_tac_toe_tests[] = {
    { "turn", NULL, NULL, NULL, NULL, turn_tests },
    { "init", NULL, NULL, NULL, NULL, init_tests },
    { "map_check", NULL, NULL, NULL, NULL, map_check_tests },
    CU_SUITE_INFO_NULL
};

int main() {
    if (CU_initialize_registry() != CUE_SUCCESS) {
        return -1;
    };
    if (CU_register_suites(tic_tac_toe_tests) != CUE_SUCCESS) {
        return -1;
    };
    CU_basic_set_mode(CU_BRM_NORMAL);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return 0;
}
