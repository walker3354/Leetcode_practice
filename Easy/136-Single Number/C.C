#include <stdlib.h>

int singleNumber(int* nums, int numsSize) {
    if (numsSize <= 0 || nums == NULL) return -1; // should throw error
    if (numsSize == 1) return nums[0];
    int temp = 0;

    for (int i = 0; i < numsSize; i++) {
        temp = (temp ^ nums[i]);
    }
    return temp;
}