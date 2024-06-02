// Functions for the Test Suite that are called in the Macros

#pragma once

#include "../main_test.h"

internal TResult
test_true(const b32 val, 
          const char *name, 
          const u32 line) {
    TResult result;
    result.name = copy_test_name(result.name, name);
    result.expected = true;
    result.actual = val;
    result.line = line;
    result.flag = (TFlag)(val == result.expected);

    return result;
}

internal TResult
test_false(const b32 val, 
           const char *name, 
           const u32 line) {
    TResult result;
    result.name = copy_test_name(result.name, name);
    result.expected = false;
    result.actual = val;
    result.line = line;
    result.flag = (TFlag)(val == result.expected);

    return result;
}

internal TResult
test_equals(const i32 val1, const i32 val2, 
            const char *name, 
            const u32 line) {
    TResult result;
    result.name = copy_test_name(result.name, name);
    result.expected = true;
    result.actual = val1 == val2;
    result.line = line;
    result.flag = (TFlag)(result.actual == result.expected);

    return result;
}

internal TResult
test_equals(const u32 val1, const u32 val2, 
            const char *name, 
            const u32 line) {
    TResult result;
    result.name = copy_test_name(result.name, name);
    result.expected = true;
    result.actual = val1 == val2;
    result.line = line;
    result.flag = (TFlag)(result.actual == result.expected);

    return result;
}

internal TResult
test_equals(const void *val1, const void *val2, 
            const char *name, 
            const u32 line) {
    TResult result;
    result.name = copy_test_name(result.name, name);
    result.expected = true;
    result.actual = val1 == val2;
    result.line = line;
    result.flag = (TFlag)(result.actual == result.expected);

    return result;
}