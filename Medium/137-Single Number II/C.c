#include <stdlib.h>

int singleNumber(int* nums, int numsSize) {
    unsigned int result = 0;
    unsigned int* bit_counter = calloc(32, sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        for (int j = 0; j < 32; j++) {
            bit_counter[j] =
                (bit_counter[j] + ((nums[i] & (1U << j)) == 0 ? 0 : 1)) % 3;
        }
    }

    for (int i = 0; i < 32; i++) {
        result |= (bit_counter[i] << i);
    }
    return (int)result;
}

int better_memory(int* nums, int numsSize) {
    unsigned int result = 0;
    for (int i = 0; i < 32; i++) {
        unsigned int sum = 0;
        unsigned int bit_mask = (1U << i);

        for (int j = 0; j < numsSize; j++) {
            sum += ((nums[j] & bit_mask) == 0 ? 0 : 1);
        }
        sum = sum % 3;
        result |= (sum << i);
    }

    return (int)result;
}