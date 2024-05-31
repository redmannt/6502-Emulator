// Instruction definitions

#pragma once

//                                      Opcode      Mode            Bytes   Cycles

// LDA - Load Accumulator
global_var constexpr u8 INS_LDA_IM  =   0xA9;   //  Immidiate       2       2
global_var constexpr u8 INS_LDA_ZP  =   0xA5;   //  Zero Page       2       3
global_var constexpr u8 INS_LDA_ZPX =   0xB5;   //  Zero Page.X     2       4
global_var constexpr u8 INS_LDA_A   =   0xAD;   //  Absolute        3       4
global_var constexpr u8 INS_LDA_AX  =   0xBD;   //  Absolute.X      3       4 (+1)
global_var constexpr u8 INS_LDA_AY  =   0xB9;   //  Absolute.Y      3       4 (+1)
global_var constexpr u8 INS_LDA_IX  =   0xA1;   //  Indirect.X      2       6
global_var constexpr u8 INS_LDA_IY  =   0xB1;   //  Indirect.X      2       5 (+1)

// JSR - Jump to Subroutine
global_var constexpr u8 INS_JSR_A   =   0x20;   //  Absolute        3       6
