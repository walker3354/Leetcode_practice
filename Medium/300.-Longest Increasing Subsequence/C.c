#include <stdlib.h>

int lengthOfLIS(int* nums, int numsSize) {
    if (numsSize <= 0) return 0;
    if (numsSize == 1) return 1;

    int* temp = malloc(numsSize * sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        temp[i] = 1;
    }

    for (int i = 1; i < numsSize; i++) {
        int j = i - 1;
        while (j >= 0) {
            if (nums[j] < nums[i])
                temp[i] = temp[i] > temp[j] ? temp[i] : temp[j] + 1;
            j--;
        }
    }
    int result = temp[0];
    for (int i = 1; i < numsSize; i++) {
        result = result > temp[i] ? result : temp[i];
    }
    free(temp);
    
    return result;
}