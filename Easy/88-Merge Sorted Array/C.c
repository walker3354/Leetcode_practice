#include <stdlib.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    if (nums2Size <= 0) return;

    m = m - 1;
    n = n - 1;

    for (int i = nums1Size - 1; i >= 0; i--) {
        if (m > -1 && (n <= -1 || nums1[m] >= nums2[n])) {
            nums1[i] = nums1[m--];
        } else if (n > -1 && (m <= -1 || nums1[m] < nums2[n])) {
            nums1[i] = nums2[n--];
        }
    }
}