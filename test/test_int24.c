#include "int24.h"
#include <stdio.h>
#include <assert.h>

void test_int24_conversion()
{
    int32_t test_values[] = {-8388608, -1, 0, 1, 8388607};
    for (int i = 0; i < 5; i++)
    {
        int24_t i24 = int32_to_int24(test_values[i]);
        assert(int24_to_int32(i24) == test_values[i]);
    }
    printf("Signed int24 conversion tests passed!\n");
}

void test_uint24_conversion()
{
    uint32_t test_values[] = {0, 1, 8388607, 16777215};
    for (int i = 0; i < 4; i++)
    {
        uint24_t u24 = uint32_to_uint24(test_values[i]);
        assert(uint24_to_uint32(u24) == test_values[i]);
    }
    printf("Unsigned uint24 conversion tests passed!\n");
}

int main()
{
    test_int24_conversion();
    test_uint24_conversion();
    return 0;
}
