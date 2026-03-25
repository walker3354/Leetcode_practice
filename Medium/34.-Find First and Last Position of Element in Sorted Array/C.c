#include <math.h>
#include <stdlib.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int find_left_boundary(int* nums, int numSize, int target);
int find_right_boundary(int* nums, int numSize, int target);

int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int* result = malloc(2 * sizeof(int));
    *returnSize = 2;
    result[0] = -1;
    result[1] = -1;
    if (numsSize <= 0) return result;
    result[0] = find_left_boundary(nums, numsSize, target);
    result[1] = find_right_boundary(nums, numsSize, target);

    return result;
}

int find_left_boundary(int* nums, int numSize, int target) {
    int left = 0;
    int right = numSize - 1;
    int result = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            result = mid;
            right = mid - 1;
        } else if (target < nums[mid]) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return result;
}

int find_right_boundary(int* nums, int numSize, int target) {
    int left = 0;
    int right = numSize - 1;
    int result = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            result = mid;
            left = mid + 1;
        } else if (target < nums[mid]) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return result;
}