#ifndef CPU_H
#define CPU_H

#include <stdint.h>
#include "memoria.h"

#define NUM_REGS     16
#define WORD_SIZE    4

typedef struct {
    uint32_t reg[NUM_REGS];
    uint32_t pc;
    uint8_t  running;
    uint32_t instruction_count;
} CPU;

// Opcodes
#define OP_RTYPE    0x00
#define OP_LW       0x23
#define OP_SW       0x2B
#define OP_BEQ      0x04
#define OP_J        0x02

// Funciones R-type
#define FUNCT_ADD   0x20

// Prototipos
void cpu_init(CPU *cpu);
void cpu_reset(CPU *cpu);
void fetch_execute(CPU *cpu, Memoria *mem);
void cpu_dump_registros(CPU *cpu);

#endif