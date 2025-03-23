#ifndef INT24_H
#define INT24_H

#include <stdint.h>
#include <stddef.h>

typedef struct
{
    uint8_t bytes[3];
} int24_t;

typedef struct
{
    uint8_t bytes[3];
} uint24_t;

// Function declarations
int24_t int32_to_int24(int32_t value);
int32_t int24_to_int32(int24_t value);

uint24_t uint32_to_uint24(uint32_t value);
uint32_t uint24_to_uint32(uint24_t value);

void print_int24(int24_t value);
void print_uint24(uint24_t value);

// Generic X-byte to Y-byte conversion
void convert_integer(const void *src, void *dest, size_t src_size, size_t dest_size);

#endif // INT24_H
