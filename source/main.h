#pragma once

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef float       f32;
typedef double      f64;

typedef int8_t      i8;
typedef int16_t     i16;
typedef int32_t     i32;
typedef int64_t     i64;

typedef uint8_t     u8;
typedef uint16_t    u16;
typedef uint32_t    u32;
typedef uint64_t    u64;

typedef int32_t     b32;

#define local_persist static
#define global_var	  static
#define internal	  static

#if DEBUG_BUILD
#define assert(exp) if (!(exp)) {\
*(i32 *)0 = 0; \
fprintf(stderr, "\nAssert triggered in file %s, line %d\n", __FILE__, __LINE__); \
exit(1); }
#else
#define assert(exp) 
#endif

#define invalid_code_path assert(!"Invalid code path")

#define array_count(array) (sizeof(array) / sizeof((array)[0]))

#define kilobytes(x) ((x) * 1024) 
#define megabytes(x) (kilobytes(x) * 1024)
#define gigabytes(x) (megabytes(x) * 1024LL)
#define terabytes(x) (gigabytes(x) * 1024LL)
