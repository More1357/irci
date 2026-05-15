#ifndef MEMORIA_H
#define MEMORIA_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>    // ← AGREGAR ESTA LÍNEA (para size_t)

#define MEM_SIZE     65536
#define WORD_SIZE    4

typedef struct {
    uint8_t datos[MEM_SIZE];
} Memoria;

// Inicialización
void mem_init(Memoria *mem);
void mem_clear(Memoria *mem);

// Lectura/escritura
bool mem_leer_byte(Memoria *mem, uint32_t addr, uint8_t *valor);
bool mem_escribir_byte(Memoria *mem, uint32_t addr, uint8_t valor);
bool mem_leer_word(Memoria *mem, uint32_t addr, uint32_t *valor);
bool mem_escribir_word(Memoria *mem, uint32_t addr, uint32_t valor);

// Carga de programas
bool mem_cargar_binario(Memoria *mem, const char *archivo, uint32_t addr);
bool mem_cargar_programa(Memoria *mem, uint32_t *programa, size_t palabras, uint32_t addr);

// Debug
void mem_dump(Memoria *mem, uint32_t addr, uint32_t bytes);

#endif