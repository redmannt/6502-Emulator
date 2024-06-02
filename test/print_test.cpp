// Print Functions for the Test Suite

#include "main_test.h"

inline internal char*
copy_test_name(char *dest, const char *src) {
    u64 size = strlen(src)+1;
    dest = (char *)malloc(size);
    strcpy_s(dest, size, src);
    return dest;
}

inline internal void
print_test_stub(const char *name, u32 line) {
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
    internal constexpr char *t = "true";
    internal constexpr char *f = "false";

    print_test_stub(result.name, result.line);
    CMD_TEXT_RED; printf("FAIL!"); CMD_TEXT_RESET;
    printf(" => ");
    CMD_TEXT_YELLOW;
    printf(
        "Expected: \'%s\', Actual: \'%s\'\n",
        result.expected ? t : f, result.actual ? t : f
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
