int missingNumber(int* nums, int numsSize) {
    int temp = 0;
    for (int i = 0; i <= numsSize; i++) {
        temp = temp ^ i;
        if (i != numsSize) {
            temp ^= nums[i];
        }
    }
    return temp;
}