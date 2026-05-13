int missingNumber(int* nums, int numsSize) {
    int result = numsSize;
    for (int i = 0; i < numsSize; i++) {
        result ^= i;
        result ^= nums[i];
    }
    return result;
}
