// Header for CPU and Memory

#pragma once

// * Includes

#include <vcruntime_string.h>
#include <stdio.h>

#include "../lib/defines.h"
#include "instructions.h"

// * Defines

#define BIT_MASK_128                (byte)0b10000000
#define BIT_MASK_LOWER_8            (byte)0xFF

#define MAX_MEMORY                  kilobytes(64)

#define ZERO_PAGE_LOCATION          (word)0x0000
#define SYSTEM_STACK_LOCATION       (word)0x0100
#define MAIN_MEMORY_LOCATION        (word)0x0200
#define INTERRUPT_HANDLER_LOCATION  (word)0xFFFA
#define POWER_RESET_LOCATION        (word)0xFFFC
#define BRK_LOCATION                (word)0xFFFE

// * Structs

typedef struct Memory
{
    byte data[MAX_MEMORY];   // Memory with size MAX_MEMORY
} Memory;

typedef struct CPU
{
    word PC;        // Program Counter

    byte SP;        // Stack Pointer
    byte A, X, Y;   // Registers
                    // Processor Status (Bitfield)
    byte C : 1;     // Carry Flag
    byte Z : 1;     // Zero Flag
    byte I : 1;     // Interrupt Disable Flag
    byte D : 1;     // Decimal Mode Flag
    byte B : 1;     // Break Command Flag
    byte V : 1;     // Overflow Flag
    byte N : 1;     // Negative Flag
    byte   : 1;     // Unused bit
} CPU;
