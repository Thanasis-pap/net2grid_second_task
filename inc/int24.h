#ifndef INT24_H
#define INT24_H

#include <stdint.h>

// Define the uint24_t structure (3-byte unsigned integer)
typedef struct
{
    uint8_t byte1;
    uint8_t byte2;
    uint8_t byte3;
} uint24_t;

// Define the SplitInt24 structure (two 3-byte unsigned integers)
typedef struct
{
    uint24_t lower; // Lower 24 bits
    uint24_t upper; // Upper 24 bits
} SplitInt24;

// Function Prototypes
// Convert 1-byte signed integer to 3-byte integer
uint24_t toThreeByteSignedInt8(int8_t value);

// Convert 2-byte signed integer to 3-byte integer
uint24_t toThreeByteSignedInt16(int16_t value);

// Convert 4-byte signed integer to two 3-byte integers (handling overflow)
SplitInt24 toTwoThreeByteSignedInt32(int32_t value);

// Convert 8-byte signed integer to two 3-byte integers (handling overflow)
SplitInt24 toTwoThreeByteSignedInt64(int64_t value);

// Convert 1-byte unsigned integer to 3-byte integer
uint24_t toThreeByteUnsignedInt8(uint8_t value);

// Convert 2-byte unsigned integer to 3-byte integer
uint24_t toThreeByteUnsignedInt16(uint16_t value);

// Convert 4-byte unsigned integer to two 3-byte integers (handling overflow)
SplitInt24 toTwoThreeByteUnsignedInt32(uint32_t value);

// Convert 8-byte unsigned integer to two 3-byte integers (handling overflow)
SplitInt24 toTwoThreeByteUnsignedInt64(uint64_t value);

#endif // INT24_H
