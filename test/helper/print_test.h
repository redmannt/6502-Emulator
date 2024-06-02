// Print Functions for the Test Suite

#pragma once

#include "../main_test.h"

// * Inline

inline internal void
print_test_stub(const char *name, u32 line) {
    printf("Test Case <%s> on line %d . . . ",
            name, line);
}

// * Functions

internal char*
copy_test_name(char *dest, const char *src) {
    u64 size = strlen(src)+1;
    dest = (char *)malloc(size);
    strcpy_s(dest, size, src);
    return dest;
}

internal void
print_test_success(TResult result) {
    print_test_stub(result.name, result.line);
    CMD_TEXT_GREEN; printf("SUCCESS!\n"); CMD_TEXT_RESET;
}

internal void
print_test_fail(TResult result) {
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
print_test_result(TResult result) {
    switch (result.flag) {
    case FAIL: {
        print_test_fail(result);
    } break;
    case SUCCESS: {
        print_test_success(result);
    } break;

    default:
        invalid_code_path;
        break;
    }

    free(result.name);
}
