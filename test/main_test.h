#pragma once

// * Includes

#include <stdlib.h>
#include "../source/main_6502.h"

// * Defines

#define CMD_TEXT_RED    printf("\x1b[31m")
#define CMD_TEXT_GREEN  printf("\x1b[32m")
#define CMD_TEXT_YELLOW printf("\x1b[33m")
#define CMD_TEXT_RESET  printf("\x1b[m")

// * Structs / Enums

typedef enum Test_Flag {
    DEFAULT = -1,
    FAIL = 0,
    SUCCESS = 1
} Test_Flag;

typedef struct Test_Result
{
    Test_Flag flag = DEFAULT;
    u32 line;
    char *name;

    b32 expected;
    b32 actual;
} Test_Result;
