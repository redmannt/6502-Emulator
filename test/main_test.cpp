// Main entry point for test suite

#include "main_test.h"
#include "print_test.cpp"

internal Test_Result
test_true(b32 val, 
          const char *name, 
          u32 line) {
    Test_Result result;
    result.name = copy_test_name(result.name, name);
    result.expected = true;
    result.actual = val;
    result.line = line;
    result.flag = (Test_Flag)(val == result.expected);

    return result;
}

internal Test_Result
test_false(b32 val, 
           const char *name, 
           u32 line) {
    Test_Result result;
    result.name = copy_test_name(result.name, name);
    result.expected = false;
    result.actual = val;
    result.line = line;
    result.flag = (Test_Flag)(val == result.expected);

    return result;
}

#define TEST_TRUE(x,n)  { print_test_result(test_true ((x),(n), __LINE__)); }
#define TEST_FALSE(x,n) { print_test_result(test_false((x),(n), __LINE__)); }

internal void
run_all_tests() {
    TEST_TRUE(5 == 5, "test success")
    TEST_TRUE(5 == 6, "test fail")
}

// * Main

i32 main() {
    printf("Running Test Suite . . .\n\n");
    run_all_tests();
    printf("\nTest Suite completed!\n");

    return 0;
}
