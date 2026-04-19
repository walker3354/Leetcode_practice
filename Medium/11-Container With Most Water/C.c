#include <math.h>

int maxArea(int* height, int heightSize) {
    if (heightSize < 2) return 0;

    int left = 0;
    int right = heightSize - 1;

    int max_result =
        (height[left] <= height[right] ? height[left] : height[right]) *
        (right - left);

    while (left < right) {
        if (height[left] <= height[right]) {
            left++;
        } else {
            right--;
        }
        int temp =
            (height[left] <= height[right] ? height[left] : height[right]) *
            (right - left);
        max_result = fmax(max_result, temp);
    }
    return max_result;
}

