// Print Functions for the Test Suite

#pragma once

#include "../main_test.h"

// * Constants

global_var constexpr s_t MAX_LENGTH_TEST_NAME = 50;

// * Functions

internal char*
copy_test_name(char *dest, 
               const char *src) {
    s_t size = strnlen_s(src, MAX_LENGTH_TEST_NAME)+1;
    dest = (char *)malloc(size);
    strcpy_s(dest, size, src);
    return dest;
}

internal void
print_test_stub(const char *name, 
                const u32 line) {
    printf("Test Case <"); 
    CMD_TEXT_CYAN;    printf("%s", name);  CMD_TEXT_RESET;     
    printf("> on line ");
    CMD_TEXT_CYAN; printf("%d ", line); CMD_TEXT_RESET;
    printf(". . . ");
}

internal void
print_test_success(Test_Result result) {
    print_test_stub(result.name, result.line);
    CMD_TEXT_GREEN; printf("SUCCESS!\n"); CMD_TEXT_RESET;
}

internal void
print_test_fail(Test_Result result) {
    local_persist constexpr char *t = "true";
    local_persist constexpr char *f = "false";

    print_test_stub(result.name, result.line);
    CMD_TEXT_RED; printf("FAIL!"); CMD_TEXT_RESET;
    printf(" => ");
    CMD_TEXT_YELLOW;
    printf("Expected: \'%s\', Actual: \'%s\'\n",
            result.expected ? t : f, result.actual ? t : f);
    CMD_TEXT_RESET;
}

internal void
print_test_result(Test_Result result) {
    switch (result.flag) {
    case SUCCESS: {
        print_test_success(result);
    } break;
    case FAIL: {
        print_test_fail(result);
    } break;

    default:
        invalid_code_path;
        break;
    }

    easy_free(result.name);
}
