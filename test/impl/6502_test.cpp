#include "6502_test.h"

b32
MyFirstTest::run() {
    printf("T1 run\n");
    return true;
}

b32 
MySecondTest::run() {
    printf("T2 run\n");
    return false;
}

b32 
MyThirdTest::run() {
    printf("T3 run\n");
    return true;
}
