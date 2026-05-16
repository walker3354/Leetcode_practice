#include <stdlib.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* countBits(int n, int* returnSize) {
    if (n < 0) {
        *returnSize = 0;
        return NULL;
    }

    *returnSize = n + 1;
    int* result = calloc(*returnSize, sizeof(int));
    result[0] = 0;

    for (int i = 1; i < *returnSize; i++) {
        result[i] = result[i & (i - 1)] + 1;
    }
    return result;
}