
#include "base.h"
#include "print.cpp"

namespace Test_Lib {

    Test_Suite::Test_Suite() { 
        CMD_TEXT_CYAN; printf("\nRunning Test Suite . . .\n\n"); CMD_TEXT_RESET; 
    }
    Test_Suite::~Test_Suite() { 
        CMD_TEXT_CYAN; printf("\nTest Suite completed!\n"); CMD_TEXT_RESET; 
    }

    void 
    Test_Suite::run_all_tests() {
        for (auto test : m_tests) {
            b32 result = test->run();
            add_test_result(result);
        }
    }

    void 
    Test_Suite::print_test_results() {
        local constexpr char *s = "\x1b[32mSUCCESS\x1b[m";
        local constexpr char *f = "\x1b[31mFAIL\x1b[m";

        i32 count = 1;
        for (auto r : m_results) {
            printf(" >> Result Test %d: %s\n", count, r ? s : f);
            count++;
        }
    }
}
