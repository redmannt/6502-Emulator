// Main

#include "main.h"

i32 main() {
    CPU cpu;
    Memory mem;

    reset(&cpu, &mem);
    execute(&cpu, &mem, 4);

    return 0;
}
