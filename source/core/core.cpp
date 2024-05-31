// CPU and Memory implementation

#include "core.h"

// * Inline functions

inline internal u8 
get_byte_from_memory(Memory *mem, 
                     u16 adr) {
    assert(adr < MAX_MEMORY);
    return mem->_data[adr];
}

// * Functions

internal void 
init_memory(Memory *mem) {
    memset(mem->_data, 0, MAX_MEMORY);
    mem->_data[MAIN_MEMORY_LOCATION]   = INS_LDA_IM; // @Cleanup: Test
    mem->_data[MAIN_MEMORY_LOCATION+1] = 0xFF;
}

internal void 
reset(CPU* cpu, 
      Memory* mem) {
    memset(cpu, 0, sizeof(CPU));

    cpu->PC = POWER_RESET_LOCATION;
/*
//  cpu->SP = (u8)(SYSTEM_STACK_LOCATION & BIT_MASK_LOWER_8);    
    We could set the stack pointer to the lower 8 bytes of the system stack address, 
    but that would be 0, which SP already is...
*/
    init_memory(mem);

    cpu->PC = MAIN_MEMORY_LOCATION;
}

internal u8 
fetch_byte(CPU *cpu,
           Memory *mem,
           u8 *cycles) {
    (*cycles)--;
    return get_byte_from_memory(mem, cpu->PC++);
}

internal void 
execute(CPU *cpu, 
       Memory *mem,
       u8 cycles) {
    while (cycles > 0) {
        u8 ins = fetch_byte(cpu, mem, &cycles);
        
        switch (ins){
        case INS_LDA_IM: {
            u8 val = fetch_byte(cpu, mem, &cycles);
            cpu->A = val;
            cpu->Z = (val == 0);
            cpu->N = (val & BIT_MASK_128) > 0;
        } break;
        
        default: {
            printf("Unknown instruction: %d\n", ins);
        } break;
        }
    }
}
