// Main entry point for test suite

#include "main_test.h"

using Test_Lib::TSuite;

i32
main() {
    TSuite suite;
    
    T1 t1;
    suite.add_test(&t1);
    T2 t2;
    suite.add_test(&t2);
    T3 t3;
    suite.add_test(&t3);

    suite.run_all_tests();
    suite.print_test_results();

    return 0;
}

#if 0
#define TEST_TRUE(v1,n)   { print_test_result(test_true      ((v1),(n),      __LINE__)); }
#define TEST_FALSE(v1,n)  { print_test_result(test_false     ((v1),(n),      __LINE__)); }
#define TEST_EQ(v1,v2,n)  { print_test_result(test_equals    ((v1),(v2),(n), __LINE__)); }
#define TEST_NEQ(v1,v2,n) { print_test_result(test_not_equals((v1),(v2),(n), __LINE__)); }
#endif
