// Typedefs and Defines

#pragma once

#include <stdint.h>
#include <assert.h>
#include <stdio.h>

typedef float    f32;
typedef double   f64;

typedef int8_t   i8;
typedef int16_t  i16;
typedef int32_t  i32;
typedef int64_t  i64;

typedef uint8_t  u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef int32_t  b32;

typedef u8       byte;
typedef u16      word;

typedef size_t   s_t;

#define local    static
#define global   static
#define internal static

#define invalid_code_path assert(!"Invalid code path")

#define array_count(array) (sizeof(array) / sizeof((array)[0]))

#define kilobytes(x) ((x) * 1024) 
#define megabytes(x) (kilobytes(x) * 1024)
#define gigabytes(x) (megabytes(x) * 1024LL)
#define terabytes(x) (gigabytes(x) * 1024LL)

// * Defines

#define CMD_TEXT_RED     printf("\x1b[31m")
#define CMD_TEXT_GREEN   printf("\x1b[32m")
#define CMD_TEXT_YELLOW  printf("\x1b[33m")
#define CMD_TEXT_MAGENTA printf("\x1b[35m")
#define CMD_TEXT_CYAN    printf("\x1b[36m")
#define CMD_TEXT_RESET   printf("\x1b[m")
