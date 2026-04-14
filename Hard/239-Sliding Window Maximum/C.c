#include <stdlib.h>

int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    if (numsSize < k || k < 0) {
        *returnSize = 0;
        return NULL;
    }

    *returnSize = numsSize - k + 1;
    int* result = malloc(*returnSize * sizeof(int));
    int* dequeue = malloc(numsSize * sizeof(int));
    int front = 0, tail = -1;

    for (int i = 0; i < numsSize; i++) {
        while (front <= tail && dequeue[front] < (i - k + 1)) front++;
        while (front <= tail && nums[dequeue[tail]] <= nums[i]) tail--;

        dequeue[++tail] = i;
        if (i >= k - 1) result[i - k + 1] = nums[dequeue[front]];
    }
    free(dequeue);
    return result;
}