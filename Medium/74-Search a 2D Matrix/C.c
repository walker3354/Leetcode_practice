#include <stdbool.h>
#include <stdlib.h>

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize,
                  int target) {
    if (matrixColSize == 0 || matrixColSize[0] == 0) return false;
    int left = 0;
    int right = matrixSize * (matrixColSize[0]) - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        int mid_value = matrix[mid / matrixColSize[0]][mid % matrixColSize[0]];
        if (mid_value == target) return true;

        if (mid_value < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return false;
}