#include <stdbool.h>
#include <stdlib.h>

bool canPartition(int* nums, int numsSize) {
    if (numsSize <= 1) return false;

    int total = 0;
    for (int i = 0; i < numsSize; i++) {
        total += nums[i];
    }
    if (total % 2 != 0) return false;

    bool* temp = calloc(((total / 2) + 1), sizeof(bool));
    temp[0] = true;
    bool final_result;
    for (int i = 0; i < numsSize; i++) {
        for (int j = total / 2; j >= nums[i]; j--) {
            temp[j] = temp[j] || temp[j - nums[i]];
        }
    }

    final_result = temp[total / 2];
    free(temp);
    return final_result;
}