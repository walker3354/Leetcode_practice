#include <stdbool.h>

int getSum(int a, int b) {
    unsigned int temp = 0;
    unsigned int result = 0;

    for (int i = 0; i < 32; i++) {
        int bit_counter = (temp != 0 ? 1 : 0);
        bool a_bit = a & (1U << i);
        bool b_bit = b & (1U << i);

        result |= ((a_bit ^ b_bit ^ temp) << i);
        if (a_bit) bit_counter++;
        if (b_bit) bit_counter++;

        if (bit_counter >= 2) {
            temp = 1;
        } else {
            temp = 0;
        }
    }
    return (int)result;
}