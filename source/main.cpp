// Main Entry Point

#include "lib/main_6502.h"

i32 main() {
    CPU cpu;
    Memory mem;

    reset(&cpu, &mem);

    cpu.X = 0xFF;
    mem._data[MAIN_MEMORY_LOCATION]   = INS_LDA_ZPX;
    mem._data[MAIN_MEMORY_LOCATION+1] = 0x80;
    mem._data[0x007F] = 0x37;

    execute(&cpu, &mem, 4);

    assert(cpu.A == 0x37);

    return 0;
}
