#include <stdlib.h>

int removeDuplicates(int* nums, int numsSize) {
    if (numsSize <= 1) return numsSize;

    int unique_pos = 0;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] != nums[unique_pos]) {
            unique_pos += 1;
            nums[unique_pos] = nums[i];
        }
    }
    return unique_pos + 1;
}