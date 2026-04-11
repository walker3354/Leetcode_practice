#include <limits.h>
#include <math.h>

int minSubArrayLen(int target, int* nums, int numsSize) {
    if (numsSize <= 0) return 0;

    int result = INT_MAX;
    int left = 0, sum = 0;
    for (int right = 0; right < numsSize; right++) {
        sum += nums[right];
        while (sum >= target) {
            result = fmin(result, right - left + 1);
            sum -= nums[left];
            left++;
        }
    }
    return result == INT_MAX ? 0 : result;
}