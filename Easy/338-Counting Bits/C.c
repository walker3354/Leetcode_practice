#include <stdlib.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* countBits(int n, int* returnSize) {
    if (n < 0) {
        *returnSize = 0;
        return NULL;
    }

    int* result = calloc(n + 1, sizeof(int));
    *returnSize = n + 1;

    for (int i = 1; i <= n; i++) {
        result[i] = result[i & (i - 1)] + 1;
    }
    return result;
}