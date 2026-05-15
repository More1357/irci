#include "cpu.h"
#include <stdio.h>
#include <string.h>

typedef struct {
    uint32_t opcode;
    uint32_t rs;
    uint32_t rt;
    uint32_t rd;
    uint32_t shamt;
    uint32_t funct;
    int32_t  imm;
    uint32_t target;
} DecodedInst;

static DecodedInst decode(uint32_t instruction) {
    DecodedInst dec = {0};
    dec.opcode = (instruction >> 26) & 0x3F;
    dec.rs     = (instruction >> 21) & 0x1F;
    dec.rt     = (instruction >> 16) & 0x1F;
    dec.rd     = (instruction >> 11) & 0x1F;
    dec.shamt  = (instruction >> 6)  & 0x1F;
    dec.funct  = instruction & 0x3F;
    dec.imm    = (int16_t)(instruction & 0xFFFF);
    dec.target = instruction & 0x3FFFFFF;
    return dec;
}

void cpu_init(CPU *cpu) {
    memset(cpu->reg, 0, sizeof(cpu->reg));
    cpu->pc = 0;
    cpu->running = 1;
    cpu->instruction_count = 0;
}

void cpu_reset(CPU *cpu) {
    cpu_init(cpu);
    printf("CPU reiniciada\n");
}

void fetch_execute(CPU *cpu, Memoria *mem) {
    uint32_t instruction;
    
    // Fetch
    if (!mem_leer_word(mem, cpu->pc, &instruction)) {
        printf("Error: fallo en fetch en PC=%08X\n", cpu->pc);
        cpu->running = 0;
        return;
    }
    
    cpu->pc += WORD_SIZE;
    cpu->instruction_count++;
    
    // Decode
    DecodedInst inst = decode(instruction);
    
    // Execute
    switch(inst.opcode) {
        case OP_RTYPE:
            if (inst.funct == FUNCT_ADD) {
                cpu->reg[inst.rd] = cpu->reg[inst.rs] + cpu->reg[inst.rt];
            } else {
                printf("Funct no soportado: %02X\n", inst.funct);
                cpu->running = 0;
            }
            break;
            
        case OP_LW: {
            uint32_t addr = cpu->reg[inst.rs] + inst.imm;
            uint32_t valor;
            if (mem_leer_word(mem, addr, &valor)) {
                cpu->reg[inst.rt] = valor;
            } else {
                printf("Error: LW dirección inválida %08X\n", addr);
                cpu->running = 0;
            }
            break;
        }
            
        case OP_SW: {
            uint32_t addr = cpu->reg[inst.rs] + inst.imm;
            if (!mem_escribir_word(mem, addr, cpu->reg[inst.rt])) {
                printf("Error: SW dirección inválida %08X\n", addr);
                cpu->running = 0;
            }
            break;
        }
            
        case OP_BEQ:
            if (cpu->reg[inst.rs] == cpu->reg[inst.rt]) {
                cpu->pc += (inst.imm << 2);
            }
            break;
            
        case OP_J:
            cpu->pc = (cpu->pc & 0xF0000000) | (inst.target << 2);
            break;
            
        default:
            printf("Opcode no soportado: %02X en PC=%08X\n", 
                   inst.opcode, cpu->pc - WORD_SIZE);
            cpu->running = 0;
            break;
    }
}

void cpu_dump_registros(CPU *cpu) {
    printf("\n=== CPU State ===\n");
    printf("PC: 0x%08X\n", cpu->pc);
    printf("Instrucciones ejecutadas: %u\n", cpu->instruction_count);
    printf("Registros:\n");
    for (int i = 0; i < NUM_REGS; i++) {
        printf("R%d: 0x%08X (%u)", i, cpu->reg[i], cpu->reg[i]);
        if ((i + 1) % 4 == 0) printf("\n");
        else printf("  ");
    }
    printf("\n");
}