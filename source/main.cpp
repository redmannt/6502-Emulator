// Main Entry Point

#include "lib/main_6502.h"

i32 main() {
    printf("Entering main entry point . . .\n");

    CPU cpu;
    Memory mem;

    printf("Starting up . . .\n");

    reset(&cpu, &mem);

    cpu.X = 0xFF;
    mem._data[MAIN_MEMORY_LOCATION] = INS_LDA_ZPX;
    mem._data[MAIN_MEMORY_LOCATION+1] = 0x80;
    mem._data[0x007F] = 0x37;

    printf("Executing code . . .\n");

    execute(&cpu, &mem, 4);

    assert(cpu.A == 0x37);

    printf("Power down . . .\n");

    return 0;
}
