#include <math.h>
#include <stdlib.h>

int rob(int* nums, int numsSize) {
    if (numsSize <= 0) return 0;
    if (numsSize == 1) return nums[0];

    int tail_money = nums[0];
    int prev_money = fmax(tail_money, nums[1]);
    for (int i = 2; i < numsSize; i++) {
        if (nums[i] + tail_money > prev_money) {
            int temp = tail_money;
            tail_money = prev_money;
            prev_money = temp + nums[i];
        } else {
            tail_money = prev_money;
        }
    }
    return tail_money >= prev_money ? tail_money : prev_money;
}