#include "int24.h"
#include <stdio.h>
#include <stdint.h>
#include <assert.h>

void printByteArray(uint24_t value)
{
    printf("Byte1: 0x%02X, Byte2: 0x%02X, Byte3: 0x%02X\n", value.byte1, value.byte2, value.byte3);
}

void printSplitInt24(SplitInt24 value)
{
    printf("Lower - Byte1: 0x%02X, Byte2: 0x%02X, Byte3: 0x%02X\n", value.lower.byte1, value.lower.byte2, value.lower.byte3);
    printf("Upper - Byte1: 0x%02X, Byte2: 0x%02X, Byte3: 0x%02X\n", value.upper.byte1, value.upper.byte2, value.upper.byte3);
}

int main()
{
    // Test toThreeByteSignedInt8
    printf("Testing toThreeByteSignedInt8\n");
    int8_t testValue8 = 127;
    uint24_t result8 = toThreeByteSignedInt8(testValue8);
    printByteArray(result8); // Expected: Byte1: 0x00, Byte2: 0x00, Byte3: 0x7F

    testValue8 = -128;
    result8 = toThreeByteSignedInt8(testValue8);
    printByteArray(result8); // Expected: Byte1: 0xFF, Byte2: 0xFF, Byte3: 0x80

    // Test toThreeByteSignedInt16
    printf("\nTesting toThreeByteSignedInt16\n");
    int16_t testValue16 = 32767;
    uint24_t result16 = toThreeByteSignedInt16(testValue16);
    printByteArray(result16); // Expected: Byte1: 0x00, Byte2: 0x7F, Byte3: 0xFF

    testValue16 = -32768;
    result16 = toThreeByteSignedInt16(testValue16);
    printByteArray(result16); // Expected: Byte1: 0xFF, Byte2: 0x80, Byte3: 0x00

    // Test toThreeByteUnsignedInt8
    printf("\nTesting toThreeByteUnsignedInt8\n");
    uint8_t testValueU8 = 255;
    uint24_t resultU8 = toThreeByteUnsignedInt8(testValueU8);
    printByteArray(resultU8); // Expected: Byte1: 0x00, Byte2: 0x00, Byte3: 0xFF

    // Test toThreeByteUnsignedInt16
    printf("\nTesting toThreeByteUnsignedInt16\n");
    uint16_t testValueU16 = 65535;
    uint24_t resultU16 = toThreeByteUnsignedInt16(testValueU16);
    printByteArray(resultU16); // Expected: Byte1: 0x00, Byte2: 0xFF, Byte3: 0xFF

    // Test toTwoThreeByteSignedInt32
    printf("\nTesting toTwoThreeByteSignedInt32\n");
    int32_t testValue32 = 8388607; // Maximum 3-byte signed value
    SplitInt24 result32 = toTwoThreeByteSignedInt32(testValue32);
    printSplitInt24(result32); // Expected: Lower - Byte1: 0x00, Byte2: 0x7F, Byte3: 0xFF, Upper - Byte1: 0x00, Byte2: 0x00, Byte3: 0x00

    testValue32 = -8388608; // Minimum 3-byte signed value
    result32 = toTwoThreeByteSignedInt32(testValue32);
    printSplitInt24(result32); // Expected: Lower - Byte1: 0xFF, Byte2: 0x80, Byte3: 0x00, Upper - Byte1: 0xFF, Byte2: 0xFF, Byte3: 0xFF

    // Test toTwoThreeByteUnsignedInt32
    printf("\nTesting toTwoThreeByteUnsignedInt32\n");
    uint32_t testValueU32 = 16777215; // Maximum 3-byte unsigned value
    SplitInt24 resultU32 = toTwoThreeByteUnsignedInt32(testValueU32);
    printSplitInt24(resultU32); // Expected: Lower - Byte1: 0xFF, Byte2: 0xFF, Byte3: 0xFF, Upper - Byte1: 0x00, Byte2: 0x00, Byte3: 0x00

    // Test toTwoThreeByteSignedInt64
    printf("\nTesting toTwoThreeByteSignedInt64\n");
    int64_t testValue64 = 8388607; // Maximum 3-byte signed value
    SplitInt24 result64 = toTwoThreeByteSignedInt64(testValue64);
    printSplitInt24(result64); // Expected: Lower - Byte1: 0x00, Byte2: 0x7F, Byte3: 0xFF, Upper - Byte1: 0x00, Byte2: 0x00, Byte3: 0x00

    testValue64 = -8388608; // Minimum 3-byte signed value
    result64 = toTwoThreeByteSignedInt64(testValue64);
    printSplitInt24(result64); // Expected: Lower - Byte1: 0xFF, Byte2: 0x80, Byte3: 0x00, Upper - Byte1: 0xFF, Byte2: 0xFF, Byte3: 0xFF

    // Test toTwoThreeByteUnsignedInt64
    printf("\nTesting toTwoThreeByteUnsignedInt64\n");
    uint64_t testValueU64 = 16777215; // Maximum 3-byte unsigned value
    SplitInt24 resultU64 = toTwoThreeByteUnsignedInt64(testValueU64);
    printSplitInt24(resultU64); // Expected: Lower - Byte1: 0xFF, Byte2: 0xFF, Byte3: 0xFF, Upper - Byte1: 0x00, Byte2: 0x00, Byte3: 0x00

    return 0;
}
