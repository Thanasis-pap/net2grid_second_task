#include "int24.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Convert 1-byte signed integer to 3-byte integer
uint24_t toThreeByteSignedInt8(int8_t value)
{
    uint24_t result;
    if (value >= 0)
    {
        result.byte1 = 0;
        result.byte2 = 0;
        result.byte3 = (uint8_t)value; // Directly store the positive value
    }
    else
    {
        result.byte1 = 0xFF;
        result.byte2 = 0xFF;
        result.byte3 = (uint8_t)(256 + value); // Two's complement conversion
    }
    return result;
}

// Convert 2-byte signed integer to 3-byte integer
uint24_t toThreeByteSignedInt16(int16_t value)
{
    uint24_t result;
    if (value >= 0)
    {
        result.byte1 = 0;
        result.byte2 = (uint8_t)(value >> 8);
        result.byte3 = (uint8_t)value;
    }
    else
    {
        result.byte1 = 0xFF;
        result.byte2 = (uint8_t)((value >> 8) & 0xFF);
        result.byte3 = (uint8_t)((256 + value) & 0xFF); // Two's complement
    }
    return result;
}

/// Convert 4-byte signed integer to two 3-byte integers (handling overflow)
SplitInt24 toTwoThreeByteSignedInt32(int32_t value)
{
    SplitInt24 result;
    if (value >= -(1 << 23) && value < (1 << 23))
    {
        // Fits within 3-byte signed range
        result.lower.byte1 = (uint8_t)(value >> 16);
        result.lower.byte2 = (uint8_t)(value >> 8);
        result.lower.byte3 = (uint8_t)value;
        result.upper.byte1 = 0;
        result.upper.byte2 = 0;
        result.upper.byte3 = 0;
    }
    else
    {
        // Overflow: split the 32-bit integer into two 24-bit integers
        result.lower.byte1 = (uint8_t)(value >> 16);
        result.lower.byte2 = (uint8_t)(value >> 8);
        result.lower.byte3 = (uint8_t)value;
        result.upper.byte1 = (uint8_t)(value >> 40);
        result.upper.byte2 = (uint8_t)(value >> 32);
        result.upper.byte3 = (uint8_t)(value >> 24);
    }
    return result;
}

// Convert 8-byte signed integer to two 3-byte integers (handling overflow)
SplitInt24 toTwoThreeByteSignedInt64(int64_t value)
{
    SplitInt24 result;
    if (value >= -(1 << 23) && value < (1 << 23))
    {
        // Fits within 3-byte signed range
        result.lower.byte1 = (uint8_t)(value >> 16);
        result.lower.byte2 = (uint8_t)(value >> 8);
        result.lower.byte3 = (uint8_t)value;
        result.upper.byte1 = 0;
        result.upper.byte2 = 0;
        result.upper.byte3 = 0;
    }
    else
    {
        // Overflow: split the 64-bit integer into two 24-bit integers
        result.lower.byte1 = (uint8_t)(value >> 16);
        result.lower.byte2 = (uint8_t)(value >> 8);
        result.lower.byte3 = (uint8_t)value;
        result.upper.byte1 = (uint8_t)(value >> 40);
        result.upper.byte2 = (uint8_t)(value >> 32);
        result.upper.byte3 = (uint8_t)(value >> 24);
    }
    return result;
}
// Convert 1-byte unsigned integer to 3-byte integer
uint24_t toThreeByteUnsignedInt8(uint8_t value)
{
    uint24_t result;
    result.byte1 = 0;
    result.byte2 = 0;
    result.byte3 = value;
    return result;
}

// Convert 2-byte unsigned integer to 3-byte integer
uint24_t toThreeByteUnsignedInt16(uint16_t value)
{
    uint24_t result;
    result.byte1 = 0;
    result.byte2 = (uint8_t)(value >> 8);
    result.byte3 = (uint8_t)value;
    return result;
}

// Convert 4-byte unsigned integer to two 3-byte integers (handling overflow)
SplitInt24 toTwoThreeByteUnsignedInt32(uint32_t value)
{
    SplitInt24 result;
    if (value <= 0xFFFFFF)
    {
        result.lower.byte1 = (uint8_t)(value >> 16);
        result.lower.byte2 = (uint8_t)(value >> 8);
        result.lower.byte3 = (uint8_t)value;
        result.upper.byte1 = 0;
        result.upper.byte2 = 0;
        result.upper.byte3 = 0;
    }
    else
    {
        // Overflow: split the 32-bit integer into two 24-bit integers
        result.lower.byte1 = (uint8_t)(value >> 16);
        result.lower.byte2 = (uint8_t)(value >> 8);
        result.lower.byte3 = (uint8_t)value;
        result.upper.byte1 = (uint8_t)(value >> 40);
        result.upper.byte2 = (uint8_t)(value >> 32);
        result.upper.byte3 = (uint8_t)(value >> 24);
    }
    return result;
}

// Convert 8-byte unsigned integer to two 3-byte integers (handling overflow)
SplitInt24 toTwoThreeByteUnsignedInt64(uint64_t value)
{
    SplitInt24 result;
    if (value <= 0xFFFFFF)
    {
        result.lower.byte1 = (uint8_t)(value >> 16);
        result.lower.byte2 = (uint8_t)(value >> 8);
        result.lower.byte3 = (uint8_t)value;
        result.upper.byte1 = 0;
        result.upper.byte2 = 0;
        result.upper.byte3 = 0;
    }
    else
    {
        // Overflow: split the 64-bit integer into two 24-bit integers
        result.lower.byte1 = (uint8_t)(value >> 16);
        result.lower.byte2 = (uint8_t)(value >> 8);
        result.lower.byte3 = (uint8_t)value;
        result.upper.byte1 = (uint8_t)(value >> 40);
        result.upper.byte2 = (uint8_t)(value >> 32);
        result.upper.byte3 = (uint8_t)(value >> 24);
    }
    return result;
}