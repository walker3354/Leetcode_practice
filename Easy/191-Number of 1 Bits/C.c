#include <stdint.h>

int hammingWeight(uint32_t n) {
    int bit_counter = 0;
    while (n != 0) {
        bit_counter++;
        n &= (n - 1);
    }

    return bit_counter;
}