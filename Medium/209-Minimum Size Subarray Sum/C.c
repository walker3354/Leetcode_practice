#include <limits.h>

int minSubArrayLen(int target, int* nums, int numsSize) {
    int temp = 0, begin = 0;
    int result = INT_MAX;

    for (int i = 0; i < numsSize; i++) {
        temp += nums[i];
        while (temp >= target) {
            int len = (i - begin) + 1;
            result = result < len ? result : len;
            temp -= nums[begin++];
        }
    }
    return result == INT_MAX ? 0 : result;
}
