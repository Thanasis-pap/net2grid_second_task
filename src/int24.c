#include "int24.h"
#include <stdio.h>
#include <string.h>

// 32-bit signed int to 24-bit signed int
int24_t int32_to_int24(int32_t value)
{
    int24_t result;
    result.bytes[0] = (uint8_t)(value & 0xFF);
    result.bytes[1] = (uint8_t)((value >> 8) & 0xFF);
    result.bytes[2] = (uint8_t)((value >> 16) & 0xFF);
    return result;
}

// 24-bit signed int to 32-bit signed int
int32_t int24_to_int32(int24_t value)
{
    int32_t result = (value.bytes[2] & 0x80) ? 0xFF000000 : 0;
    result |= value.bytes[0] | (value.bytes[1] << 8) | (value.bytes[2] << 16);
    return result;
}

// 32-bit unsigned int to 24-bit unsigned int
uint24_t uint32_to_uint24(uint32_t value)
{
    uint24_t result;
    result.bytes[0] = (uint8_t)(value & 0xFF);
    result.bytes[1] = (uint8_t)((value >> 8) & 0xFF);
    result.bytes[2] = (uint8_t)((value >> 16) & 0xFF);
    return result;
}

// 24-bit unsigned int to 32-bit unsigned int
uint32_t uint24_to_uint32(uint24_t value)
{
    return value.bytes[0] | (value.bytes[1] << 8) | (value.bytes[2] << 16);
}

void convert_integer(const void *src, void *dest, size_t src_size, size_t dest_size)
{
    memcpy(dest, src, dest_size < src_size ? dest_size : src_size);
}

void print_int24(int24_t value)
{
    printf("int24: 0x%02X%02X%02X (%d)\n", value.bytes[2], value.bytes[1], value.bytes[0], int24_to_int32(value));
}

void print_uint24(uint24_t value)
{
    printf("uint24: 0x%02X%02X%02X (%u)\n", value.bytes[2], value.bytes[1], value.bytes[0], uint24_to_uint32(value));
}
