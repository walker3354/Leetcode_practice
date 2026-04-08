#include <stdlib.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    if (numbersSize < 2) return NULL;

    *returnSize = 2;
    int* result = malloc(*returnSize * sizeof(int));
    int left = 0;
    int right = numbersSize - 1;
    while (left < right) {
        int temp = numbers[left] + numbers[right];
        if (target == temp) break;
        if (target > temp) left++;
        if (target < temp) right--;
    }
    result[0] = left + 1;
    result[1] = right + 1;
    return result;
}