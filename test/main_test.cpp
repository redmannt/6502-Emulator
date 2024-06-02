// Main entry point for test suite

#include "helper/print_test.h"
#include "helper/func_test.h"

#define TEST_TRUE(x,n)  { print_test_result(test_true ((x),(n), __LINE__)); }
#define TEST_FALSE(x,n) { print_test_result(test_false((x),(n), __LINE__)); }

internal void
run_all_tests() {
    TEST_TRUE(5 == 5, "test success")
    TEST_TRUE(5 == 6, "test fail")
}

i32 main() {
    printf("Running Test Suite . . .\n\n");
    run_all_tests();
    printf("\nTest Suite completed!\n");

    return 0;
}
