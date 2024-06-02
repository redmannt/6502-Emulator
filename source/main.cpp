// Main Entry Point

#include "main_6502.h"

void cpu_test() {
    printf("Testing 6502 processor . . .\n");

    CPU cpu;
    Memory mem;
    reset(&cpu, &mem);

    cpu.X = 0xFF;
    mem.data[MAIN_MEMORY_LOCATION]   = INS_LDA_ZPX;
    mem.data[MAIN_MEMORY_LOCATION+1] = 0x80;
    mem.data[0x007F] = 0x37;

    execute(&cpu, &mem, 4);
    assert(cpu.A == 0x37);

    printf(" ~ ~ ~ Success! ~ ~ ~\n");
}

void stretchy_buffer_test() {
    printf("\nTestting stretchy buffers . . .\n");

    enum { N = 1000 };
    i32 *buf = NULL;

    for (i32 i = 0; i < N; i++) {
        buf_push(buf, i);
    }
    
    assert(buf_len(buf) == N);

    for (i32 i = 0; i < N; i++) {
        assert(buf[i] == i);
    }

    buf_free(buf);

    printf("~ ~ ~ Success! ~ ~ ~\n");
}

i32 main() {
    cpu_test();
    stretchy_buffer_test();
        
    return 0;
}
