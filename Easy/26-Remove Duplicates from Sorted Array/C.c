#include <stdlib.h>

int removeDuplicates(int* nums, int numsSize) {
    if (numsSize <= 1) return numsSize;
    int insert_pos = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[insert_pos] != nums[i]) {
            nums[++insert_pos] = nums[i];
        }
    }
    return insert_pos + 1;
}