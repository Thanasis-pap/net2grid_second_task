#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "int24.h"

// Forward declaration of the conversion functions
uint24_t toThreeByteSignedInt8(int8_t value);
uint24_t toThreeByteSignedInt16(int16_t value);
uint24_t toThreeByteSignedInt32(int32_t value);
uint24_t toThreeByteSignedInt64(int64_t value);
uint24_t toThreeByteUnsignedInt8(uint8_t value);
uint24_t toThreeByteUnsignedInt16(uint16_t value);
uint24_t toThreeByteUnsignedInt32(uint32_t value);
uint24_t toThreeByteUnsignedInt64(uint64_t value);

void printThreeByteResult(uint24_t result)
{
    printf("Byte 1: 0x%02X, Byte 2: 0x%02X, Byte 3: 0x%02X\n",
           result.byte1, result.byte2, result.byte3);
}

int main()
{
    // Test 1-byte signed integer to 3-byte signed conversion
    int8_t signed8 = -50;
    uint24_t result8 = toThreeByteSignedInt8(signed8);
    printf("Testing signed 8-bit to 3-byte conversion (int8_t = %d):\n", signed8);
    printThreeByteResult(result8);

    // Test 2-byte signed integer to 3-byte signed conversion
    int16_t signed16 = -3200;
    uint24_t result16 = toThreeByteSignedInt16(signed16);
    printf("\nTesting signed 16-bit to 3-byte conversion (int16_t = %d):\n", signed16);
    printThreeByteResult(result16);

    // Test 4-byte signed integer to 3-byte signed conversion
    int32_t signed32 = 123456;
    uint24_t result32 = toThreeByteSignedInt32(signed32);
    printf("\nTesting signed 32-bit to 3-byte conversion (int32_t = %d):\n", signed32);
    printThreeByteResult(result32);

    // Test 8-byte signed integer to 3-byte signed conversion
    int64_t signed64 = -2000000;
    uint24_t result64 = toThreeByteSignedInt64(signed64);
    printf("\nTesting signed 64-bit to 3-byte conversion (int64_t = %lld):\n", signed64);
    printThreeByteResult(result64);

    // Test 1-byte unsigned integer to 3-byte unsigned conversion
    uint8_t unsigned8 = 200;
    uint24_t resultU8 = toThreeByteUnsignedInt8(unsigned8);
    printf("\nTesting unsigned 8-bit to 3-byte conversion (uint8_t = %d):\n", unsigned8);
    printThreeByteResult(resultU8);

    // Test 2-byte unsigned integer to 3-byte unsigned conversion
    uint16_t unsigned16 = 12345;
    uint24_t resultU16 = toThreeByteUnsignedInt16(unsigned16);
    printf("\nTesting unsigned 16-bit to 3-byte conversion (uint16_t = %d):\n", unsigned16);
    printThreeByteResult(resultU16);

    // Test 4-byte unsigned integer to 3-byte unsigned conversion
    uint32_t unsigned32 = 987654;
    uint24_t resultU32 = toThreeByteUnsignedInt32(unsigned32);
    printf("\nTesting unsigned 32-bit to 3-byte conversion (uint32_t = %u):\n", unsigned32);
    printThreeByteResult(resultU32);

    // Test 8-byte unsigned integer to 3-byte unsigned conversion
    uint64_t unsigned64 = 123456789;
    uint24_t resultU64 = toThreeByteUnsignedInt64(unsigned64);
    printf("\nTesting unsigned 64-bit to 3-byte conversion (uint64_t = %llu):\n", unsigned64);
    printThreeByteResult(resultU64);

    return 0;
}
