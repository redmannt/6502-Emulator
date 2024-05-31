// Header for CPU and Memory

#pragma once

// * Includes

#include <vcruntime_string.h>
#include <stdio.h>

#include "../defines.h"
#include "instructions.h"

// * Defines

#define BIT_MASK_128        (u8)0b10000000
#define BIT_MASK_LOWER_8    (u8)0xFF

#define MAX_MEMORY  kilobytes(64)

#define ZERO_PAGE_LOCATION          (u16)0x0000
#define SYSTEM_STACK_LOCATION       (u16)0x0100
#define MAIN_MEMORY_LOCATION        (u16)0x0200
#define INTERRUPT_HANDLER_LOCATION  (u16)0xFFFA
#define POWER_RESET_LOCATION        (u16)0xFFFC
#define BRK_LOCATION                (u16)0xFFFE

// * Structs

typedef struct Memory
{
    u8 _data[MAX_MEMORY];   // Memory with size MAX_MEMORY
} Memory;

typedef struct CPU
{
    u16 PC;     // Program Counter

    u8 SP;      // Stack Pointer
    u8 A, X, Y; // Registers
                // Processor status (Bitfield)
    u8 C : 1;   // Carry Flag
    u8 Z : 1;   // Zero Flag
    u8 I : 1;   // Interrupt Disable Flag
    u8 D : 1;   // Decimal Mode Flag
    u8 B : 1;   // Break Command Flag
    u8 V : 1;   // Overflow Flag
    u8 N : 1;   // Negative Flag
    u8   : 1;   // Unused bit
} CPU;
