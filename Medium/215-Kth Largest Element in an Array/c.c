#include <stdlib.h>

int compare(const void* a, const void* b) {
    int val_a = *(int*)a;
    int val_b = *(int*)b;
    return val_b - val_a;
}

int findKthLargest(int* nums, int numsSize, int k) {
    if (numsSize < k || k <= 0) return -1; // should throw error
    qsort(nums, numsSize, sizeof(int), compare);
    return nums[k - 1];
}
