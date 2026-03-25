int findMin(int* nums, int numsSize) {
    if (numsSize < 0) return -1;
    if (numsSize == 0) return nums[0];

    int left = 0;
    int right = numsSize - 1;
    while (left < right) { 
        int mid = left + (right - left) / 2;

        if (nums[mid] > nums[right]) { // break point must in right
            left = mid + 1;
        } else { // break point in left(include mid)
            right = mid;
        }
    }
    return nums[right];
}