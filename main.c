#include "cpu.h"
#include "memoria.h"
#include <stdio.h>

// Programa de ejemplo: suma dos números
static uint32_t programa_ejemplo[] = {
    0x00004020,  // add  $8, $0, $0
    0x00004820,  // add  $9, $0, $0  
    0x8D0A0000,  // lw   $10, 0($8)
    0x8D0B0004,  // lw   $11, 4($8)
    0x014B6020,  // add  $12, $10, $11
    0xAD0C0008,  // sw   $12, 8($8)
    0x1000FFFF,  // beq  $0, $0, -1
};

// Cambiar el tipo del parámetro para evitar warning
void ejecutar_hasta_fin(CPU *cpu, Memoria *mem, unsigned int max_instrucciones) {
    while (cpu->running) {
        fetch_execute(cpu, mem);
        
        if (cpu->instruction_count >= max_instrucciones) {
            printf("Límite de instrucciones alcanzado\n");
            break;
        }
    }
}

int main() {
    CPU cpu;
    Memoria mem;
    
    // Inicializar componentes
    cpu_init(&cpu);
    mem_init(&mem);
    
    // Cargar datos en memoria (posiciones 0 y 4)
    mem_escribir_word(&mem, 0, 10);
    mem_escribir_word(&mem, 4, 20);
    
    // Cargar programa (convertir size_t correctamente)
    size_t num_instrucciones = sizeof(programa_ejemplo) / sizeof(programa_ejemplo[0]);
    mem_cargar_programa(&mem, programa_ejemplo, num_instrucciones, 0);
    
    // Ejecutar
    printf("=== Iniciando ejecución ===\n");
    ejecutar_hasta_fin(&cpu, &mem, 20);
    
    // Mostrar resultados
    cpu_dump_registros(&cpu);
    
    uint32_t resultado;
    mem_leer_word(&mem, 8, &resultado);
    printf("\nResultado en Mem[8] = %u (debe ser 30)\n", resultado);
    
    return 0;
}