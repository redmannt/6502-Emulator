// Functions for the Test Suite that are called in the Macros

#pragma once

#include "../main_test.h"

// * Stub

inline internal Test_Result
test_result_stub(Test_Result *result,
                 const char *name, 
                 const u32 line,
                 const b32 expected) {
    result->name = copy_test_name(result->name, name);
    result->expected = expected;
    result->line = line;
    return *result;
}

// * TEST_TRUE

internal Test_Result
test_true(const b32 val, 
          const char *name, 
          const u32 line) {
    Test_Result result;
    result = test_result_stub(&result, name, line, true);
    result.actual = val;
    result.flag   = (Test_Flag)(result.actual == result.expected);

    return result;
}

// * TEST_FALSE

internal Test_Result
test_false(const b32 val, 
           const char *name, 
           const u32 line) {
    Test_Result result;
    result = test_result_stub(&result, name, line, false);
    result.actual = val;
    result.flag   = (Test_Flag)(result.actual == result.expected);

    return result;
}

// * TEST_EQ

internal Test_Result
test_equals(const bool val1, const bool val2, 
            const char *name, 
            const u32 line) {
    Test_Result result;
    result = test_result_stub(&result, name, line, true);
    result.actual = val1 == val2;
    result.flag   = (Test_Flag)(result.actual == result.expected);

    return result;
}

internal Test_Result
test_equals(const i64 val1, const i64 val2, 
            const char *name, 
            const u32 line) {
    Test_Result result;
    result = test_result_stub(&result, name, line, true);
    result.actual = val1 == val2;
    result.flag   = (Test_Flag)(result.actual == result.expected);

    return result;
}

internal Test_Result
test_equals(const u64 val1, const u64 val2, 
            const char *name, 
            const u32 line) {
    Test_Result result;
    result = test_result_stub(&result, name, line, true);
    result.actual = val1 == val2;
    result.flag   = (Test_Flag)(result.actual == result.expected);

    return result;
}

internal Test_Result
test_equals(const void *val1, const void *val2, 
            const char *name, 
            const u32 line) {
    Test_Result result;
    result = test_result_stub(&result, name, line, true);
    result.actual = val1 == val2;
    result.flag   = (Test_Flag)(result.actual == result.expected);

    return result;
}

// * TEST_NEQ

internal Test_Result
test_not_equals(const bool val1, const bool val2, 
                const char *name, 
                const u32 line) {
    Test_Result result;
    result = test_result_stub(&result, name, line, false);
    result.actual = val1 == val2;
    result.flag   = (Test_Flag)(result.actual == result.expected);

    return result;
}

internal Test_Result
test_not_equals(const i64 val1, const i64 val2, 
                const char *name, 
                const u32 line) {
    Test_Result result;
    result = test_result_stub(&result, name, line, false);
    result.actual = val1 == val2;
    result.flag   = (Test_Flag)(result.actual == result.expected);

    return result;
}

internal Test_Result
test_not_equals(const u64 val1, const u64 val2, 
                const char *name, 
                const u32 line) {
    Test_Result result;
    result = test_result_stub(&result, name, line, false);
    result.actual = val1 == val2;
    result.flag   = (Test_Flag)(result.actual == result.expected);

    return result;
}

internal Test_Result
test_not_equals(const void *val1, const void *val2, 
                const char *name, 
                const u32 line) {
    Test_Result result;
    result = test_result_stub(&result, name, line, false);
    result.actual = val1 == val2;
    result.flag   = (Test_Flag)(result.actual == result.expected);

    return result;
}
