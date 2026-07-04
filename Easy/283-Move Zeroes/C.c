void moveZeroes(int* nums, int numsSize) {
    if (numsSize <= 1) return;

    int zero_counter = 0;
    int number_counter = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 0) {
            zero_counter++;
        } else {
            nums[number_counter++] = nums[i];
        }
    }
    for (int i = 0; i < zero_counter; i++) {
        nums[number_counter++] = 0;
    }
}