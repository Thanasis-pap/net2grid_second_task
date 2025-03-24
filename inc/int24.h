#ifndef INT24_H
#define INT24_H

#include <stdint.h>
#include <stddef.h>

typedef struct
{
    uint8_t byte1;
    uint8_t byte2;
    uint8_t byte3;
} uint24_t;

// Function declarations for 3-byte conversions
uint24_t toThreeByteSignedInt8(int8_t value);
uint24_t toThreeByteSignedInt16(int16_t value);
uint24_t toThreeByteSignedInt32(int32_t value);
uint24_t toThreeByteSignedInt64(int64_t value);

uint24_t toThreeByteUnsignedInt8(uint8_t value);
uint24_t toThreeByteUnsignedInt16(uint16_t value);
uint24_t toThreeByteUnsignedInt32(uint32_t value);
uint24_t toThreeByteUnsignedInt64(uint64_t value);

void splitAndConvertToThreeByteInt32(uint32_t value, uint24_t *highPart, uint24_t *lowPart);
void splitAndConvertToThreeByteInt64(uint64_t value, uint24_t *highPart, uint24_t *lowPart);

#endif // INT24_H
