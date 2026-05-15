#include "memoria.h"   // ← Esto debe ser lo PRIMERO
#include <stdio.h>
#include <string.h>

// NO necesitas redefinir WORD_SIZE aquí, ya viene de memoria.h

void mem_init(Memoria *mem) {
    memset(mem->datos, 0, sizeof(mem->datos));
}

void mem_clear(Memoria *mem) {
    mem_init(mem);
}

bool mem_leer_byte(Memoria *mem, uint32_t addr, uint8_t *valor) {
    if (addr >= MEM_SIZE) {
        printf("Error: lectura fuera de límites en 0x%08X\n", addr);
        return false;
    }
    *valor = mem->datos[addr];
    return true;
}

bool mem_escribir_byte(Memoria *mem, uint32_t addr, uint8_t valor) {
    if (addr >= MEM_SIZE) {
        printf("Error: escritura fuera de límites en 0x%08X\n", addr);
        return false;
    }
    mem->datos[addr] = valor;
    return true;
}

bool mem_leer_word(Memoria *mem, uint32_t addr, uint32_t *valor) {
    if (addr + WORD_SIZE > MEM_SIZE) {  // ← WORD_SIZE viene de memoria.h
        printf("Error: lectura word fuera de límites en 0x%08X\n", addr);
        return false;
    }
    
    // Big-endian
    *valor = (mem->datos[addr] << 24) |
             (mem->datos[addr+1] << 16) |
             (mem->datos[addr+2] << 8) |
             mem->datos[addr+3];
    return true;
}

bool mem_escribir_word(Memoria *mem, uint32_t addr, uint32_t valor) {
    if (addr + WORD_SIZE > MEM_SIZE) {  // ← WORD_SIZE viene de memoria.h
        printf("Error: escritura word fuera de límites en 0x%08X\n", addr);
        return false;
    }
    
    // Big-endian
    mem->datos[addr]   = (valor >> 24) & 0xFF;
    mem->datos[addr+1] = (valor >> 16) & 0xFF;
    mem->datos[addr+2] = (valor >> 8) & 0xFF;
    mem->datos[addr+3] = valor & 0xFF;
    return true;
}

bool mem_cargar_binario(Memoria *mem, const char *archivo, uint32_t addr) {
    FILE *f = fopen(archivo, "rb");
    if (!f) {
        printf("Error: no se pudo abrir %s\n", archivo);
        return false;
    }
    
    if (addr >= MEM_SIZE) {
        printf("Error: dirección de carga inválida\n");
        fclose(f);
        return false;
    }
    
    size_t leidos = fread(&mem->datos[addr], 1, MEM_SIZE - addr, f);
    printf("Cargados %zu bytes desde %s en 0x%08X\n", leidos, archivo, addr);
    
    fclose(f);
    return true;
}

bool mem_cargar_programa(Memoria *mem, uint32_t *programa, size_t palabras, uint32_t addr) {
    for (size_t i = 0; i < palabras; i++) {
        if (!mem_escribir_word(mem, addr + (i * WORD_SIZE), programa[i])) {
            return false;
        }
    }
    return true;
}

void mem_dump(Memoria *mem, uint32_t addr, uint32_t bytes) {
    printf("\n=== Memoria dump (0x%08X, %u bytes) ===\n", addr, bytes);
    for (uint32_t i = 0; i < bytes; i++) {
        if (i % 16 == 0) printf("\n0x%08X: ", addr + i);
        printf("%02X ", mem->datos[addr + i]);
    }
    printf("\n\n");
}