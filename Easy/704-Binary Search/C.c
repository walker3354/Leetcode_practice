#include <stdlib.h>

int search(int* nums, int numsSize, int target) {
    if (numsSize <= 0) return -1;
    if (numsSize == 1) {
        if (nums[0] == target) return 0;
        return -1;
    }

    int left = 0;
    int right = numsSize - 1;
    int mid = left + (right - left) / 2;

    while (left <= right) {
        if (nums[mid] == target) return mid;
        if (nums[mid] > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
        mid = left + (right - left) / 2;
    }
    return -1;
}