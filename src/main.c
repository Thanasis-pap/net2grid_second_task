#include "int24.h"
#include <stdio.h>

int main()
{
    int32_t num = -5000000;
    uint32_t unum = 7000000;

    int24_t i24 = int32_to_int24(num);
    uint24_t u24 = uint32_to_uint24(unum);

    printf("Original 32-bit int: %d\n", num);
    print_int24(i24);
    printf("Converted back: %d\n\n", int24_to_int32(i24));

    printf("Original 32-bit uint: %u\n", unum);
    print_uint24(u24);
    printf("Converted back: %u\n", uint24_to_uint32(u24));

    return 0;
}
