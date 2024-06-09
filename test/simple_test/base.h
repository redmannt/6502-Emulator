#pragma once

// * Includes

#include <stdio.h>
#include <vector>

#include "../../source/lib/defines.h"

namespace Test_Lib {

#define CTOR_(name) name() { setup(); }
#define DTOR_(name) virtual ~name() { teardown(); }

#define CTOR(name) name() { base::setup(); setup(); }
#define DTOR(name) virtual ~name() { base::teardown(); teardown(); }

    typedef struct Test_Interface {
        virtual void setup()      = 0;
        virtual void teardown()   = 0;
        virtual b32  run()        = 0;
    } ITest;

    typedef struct Test_Suite {
        Test_Suite(); 
        ~Test_Suite();
        
        void run_all_tests();
        void print_test_results();

        inline void add_test(ITest *test) { m_tests.push_back(test); }

        private:
        inline void add_test_result(b32 result) { m_results.push_back(result); }

        private:
        std::vector<ITest*> m_tests;
        std::vector<b32>    m_results;
    } TSuite;
}
