#include <stdbool.h>

int getSum(int a, int b) {
    int temp = 0;
    unsigned result = 0;

    for (int i = 0; i < 32; i++) {
        int bit_counter = (temp == 0 ? 0 : 1);
        bool a_bit = a & (1U << i);
        bool b_bit = b & (1U << i);
        if (a_bit) bit_counter++;
        if (b_bit) bit_counter++;

        result |= ((temp ^ a_bit ^ b_bit) << i);
        if (bit_counter >= 2) {
            temp = 1;
        } else {
            temp = 0;
        }
    }
    return (int)result;
}