/**
    @author Tamara Süli
    @version 1.0.0 6/18/2020
*/

#include "display.h"
#include "utest-display.h"

#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>

CU_SuiteInfo display_suite[] = {
    { "display", NULL, NULL, NULL, NULL, display_tests },
    CU_SUITE_INFO_NULL
};

int main() {
    if (CU_initialize_registry() != CUE_SUCCESS) {
        return -1;
    };
    if (CU_register_suites(display_suite) != CUE_SUCCESS) {
        return -1;
    };
    CU_basic_set_mode(CU_BRM_NORMAL);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return 0;
}
