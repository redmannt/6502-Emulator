#pragma once

// * Includes

#include <stdio.h>
#include <string.h>

#include "../source/lib/defines.h"
#include "../source/lib/stretchy_buffer.h"

// * Defines

#define CMD_TEXT_RED        printf("\x1b[31m")
#define CMD_TEXT_GREEN      printf("\x1b[32m")
#define CMD_TEXT_YELLOW     printf("\x1b[33m")
#define CMD_TEXT_MAGENTA    printf("\x1b[35m")
#define CMD_TEXT_CYAN       printf("\x1b[36m")
#define CMD_TEXT_RESET      printf("\x1b[m")

// * Structs / Enums

typedef enum Test_Flag {
    DEFAULT = -1,
    FAIL    = 0,
    SUCCESS = 1
} TFlag;

typedef struct Test_Result
{
    TFlag flag = DEFAULT;
    u32   line;
    char *name;

    union {
        i64 expected_i64;
        u64 expected_u64;
        b32 expected; 
    };

    union {
        i64 actual_i64;
        u64 actual_u64;
        b32 actual;
    };
} TResult;
