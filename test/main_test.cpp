// Main entry point for test suite

#include "helper/print_test.h"
#include "helper/func_test.h"

#define TEST_TRUE(v1,n)   { print_test_result(test_true      ((v1),(n),      __LINE__)); }
#define TEST_FALSE(v1,n)  { print_test_result(test_false     ((v1),(n),      __LINE__)); }
#define TEST_EQ(v1,v2,n)  { print_test_result(test_equals    ((v1),(v2),(n), __LINE__)); }
#define TEST_NEQ(v1,v2,n) { print_test_result(test_not_equals((v1),(v2),(n), __LINE__)); }

internal void
run_all_tests() {
    i32 *x = easy_malloc(x); *x = -5;
    i32 *y = x;
    i32 *z = easy_malloc(z); *z = -5;
    u32 *a = easy_malloc(a); *a =  6;
    u32 *b = a;
    u32 *c = easy_malloc(c); *c =  6;

    TEST_TRUE(  true,          "test true success")
    TEST_TRUE(  false,         "test true fail")
    TEST_FALSE( false,         "test false success")
    TEST_FALSE( true,          "test false fail")
    TEST_EQ(    true,  true,   "test eq bool success")
    TEST_EQ(    true,  false,  "test eq bool success")
    TEST_EQ(    7ULL,  7ULL,   "test eq u64 success")
    TEST_EQ(    7LL,   8LL,    "test eq i64 fail")
    TEST_EQ(    x,     y,      "test eq pointer success")
    TEST_EQ(    x,     z,      "test eq pointer fail")
    TEST_NEQ(   true,  false,  "test neq bool success")
    TEST_NEQ(   false,  false, "test neq bool fail")
    TEST_NEQ(   7LL,   8LL,    "test neq i64 success")
    TEST_NEQ(   8ULL,  8ULL,   "test neq u64 fail")
    TEST_NEQ(   a,     c,      "test neq pointer success")
    TEST_NEQ(   a,     b,      "test neq pointer fail")

    easy_free(x);
    easy_free(z);
    easy_free(a);
    easy_free(c);
}

i32 
main() {
    printf("Running Test Suite . . .\n\n");
    run_all_tests();
    printf("\nTest Suite completed!\n");

    return 0;
}
