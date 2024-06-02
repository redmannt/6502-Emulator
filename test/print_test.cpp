// Print Functions for the Test Suite

#include "main_test.h"

inline internal u8*
copy_test_name(u8* dest, const char *src) {
    dest = (u8 *)malloc(sizeof(src)+1);
    return (u8 *)strcpy((char *)dest, src);
}

inline internal void
print_test_stub(u8 *name, u32 line) {
    printf(
        "Test Case <%s> on line %d . . . ",
        name, line
    );
}

internal void
print_test_success(Test_Result result) {
    print_test_stub(result.name, result.line);
    CMD_TEXT_GREEN; printf("SUCCESS!\n"); CMD_TEXT_RESET;
}

internal void
print_test_fail(Test_Result result) {
    print_test_stub(result.name, result.line);
    CMD_TEXT_RED; printf("FAIL!"); CMD_TEXT_RESET;
    printf(" => ");
    CMD_TEXT_YELLOW;
    printf(
        "Expected: %d, got %d instead\n",
        result.expected, result.actual
    );
    CMD_TEXT_RESET;
}

internal void
print_test_result(Test_Result result) {
    switch (result.flag)
    {
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
}
