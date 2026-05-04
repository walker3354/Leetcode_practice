int partition(int* nums, int left, int right) {
    int store_index = left;
    int pivot = nums[right];
    for (int i = left; i < right; i++) {
        if (nums[i] > pivot) {
            int temp = nums[i];
            nums[i] = nums[store_index];
            nums[store_index++] = temp;
        }
    }
    int temp = nums[store_index];
    nums[store_index] = nums[right];
    nums[right] = temp;
    return store_index;
}

int quickSelect(int* nums, int left, int right, int k) {
    if (left == right) return nums[left];
    int pivot_index = partition(nums, left, right); // kth big value
    int target_index = k - 1;

    if (pivot_index == target_index) {
        return nums[pivot_index];
    } else if (pivot_index < target_index) {
        return quickSelect(nums, pivot_index + 1, right, k);
    } else {
        return quickSelect(nums, left, pivot_index - 1, k);
    }
}

int findKthLargest(int* nums, int numsSize, int k) {
    return quickSelect(nums, 0, numsSize - 1, k);
}