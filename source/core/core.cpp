// CPU and Memory implementation

#include "core.h"

// * Inline functions

inline byte 
get_byte_from_memory(Memory *mem, 
                     word adr) {
    assert(adr < MAX_MEMORY);
    return mem->data[adr];
}

inline void
set_lda_flags(CPU *cpu,
              byte val) {
    cpu->Z = (val == 0);
    cpu->N = (val & BIT_MASK_128) > 0;
}

inline byte 
fetch_byte(CPU *cpu,
           Memory *mem,
           u32 *cycles) {
    (*cycles)--;
    return get_byte_from_memory(mem, cpu->PC++);
}

inline byte 
peek_byte(Memory *mem,
          word adr,
          u32 *cycles) {
    (*cycles)--;
    return get_byte_from_memory(mem, adr);
}

inline word
fetch_word(CPU *cpu,
           Memory *mem,
           u32 *cycles) {
    word data = fetch_byte(cpu, mem, cycles);
    data |= (fetch_byte(cpu, mem, cycles) << 8);
    return data;
    // @Robustness: Handle big endian
}

inline void
write_word(Memory *mem,
           word val,
           word adr,
           u32 *cycles) {
    mem->data[adr]   = val & BIT_MASK_LOWER_8;
    mem->data[adr+1] = (val >> 8); 
    (*cycles) -= 2;
}

inline void
push_stack_word(Memory *mem,
           byte *sp,
           word val,
           u32 *cycles) {
    write_word(mem, val, SYSTEM_STACK_LOCATION + *sp, cycles);
    (*sp) += 2;
}

// * Functions

void 
init_memory(Memory *mem) {
    memset(mem->data, 0, MAX_MEMORY);
}

void 
reset(CPU* cpu, 
      Memory* mem) {
    memset(cpu, 0, sizeof(CPU));

    cpu->PC = POWER_RESET_LOCATION;
/*
//  cpu->SP = (byte)(SYSTEM_STACK_LOCATION & BIT_MASK_LOWER_8);    
    We could set the stack pointer to the lower 8 bits of the system stack address, 
    but that would be 0, which SP already is...
*/
    init_memory(mem);

    cpu->PC = MAIN_MEMORY_LOCATION;
}

void 
execute(CPU *cpu, 
       Memory *mem,
       u32 cycles) {
    while (cycles > 0) {
        byte ins = fetch_byte(cpu, mem, &cycles);
        
        switch (ins){
        case INS_LDA_IM: {
            byte val = fetch_byte(cpu, mem, &cycles);
            cpu->A = val;
            set_lda_flags(cpu, val);
        } break;
        case INS_LDA_ZP: {
            byte zpa = fetch_byte(cpu, mem, &cycles);
            cpu->A = peek_byte(mem, zpa, &cycles);
            set_lda_flags(cpu, cpu->A);
        } break;
        case INS_LDA_ZPX: {
            byte zpa = fetch_byte(cpu, mem, &cycles);
            zpa += cpu->X; cycles--; // @Robustness: Handle overflow
            cpu->A = peek_byte(mem, zpa, &cycles);
            set_lda_flags(cpu, cpu->A);
        } break;
        case INS_JSR_A: {
            word sub_adr = fetch_word(cpu, mem, &cycles);
            push_stack_word(mem, &cpu->SP, cpu->PC-1, &cycles);
            cpu->PC = sub_adr;
            cycles--;
        } break;

        default: {
            printf("Unknown ins: %d\n", ins);
            invalid_code_path;
        } break;
        }

        assert(cycles >= 0);
    }

    assert(cycles == 0);
}
