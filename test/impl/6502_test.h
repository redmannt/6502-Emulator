#pragma once

#include "../simple_test/simple_test.h"
#include "../../source/core/core.cpp"

using Test_Lib::ITest;

// * Base

typedef struct Base_6502_Test : ITest {
    CTOR_(Base_6502_Test)
    DTOR_(Base_6502_Test)

    virtual void setup() override {
        printf("Base_Test setup\n");
        reset(&m_cpu, &m_mem);
    }
    virtual void teardown() override {
        printf("Base_Test teardown\n");
    }
    virtual b32 run() = 0;

    private:
    CPU m_cpu;
    Memory m_mem;
} Base_Test;

// * Test Structs

typedef struct MyFirstTest : Base_Test {
    virtual b32 run() override;    
} T1;

typedef struct MySecondTest : Base_Test {
    virtual b32 run() override;    
} T2;

typedef struct MyThirdTest : Base_Test {
    virtual b32 run() override;    
} T3;
