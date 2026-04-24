#include <stdlib.h>

void rotate(int** matrix, int matrixSize, int* matrixColSize) {
    if (matrixSize <= 0) return;

    int x_len = matrixColSize[0];
    for (int i = 0; i < matrixSize; i++) {
        for (int j = i + 1; j < x_len; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }

    int* temp = malloc(x_len * sizeof(int));
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < x_len; j++) {
            temp[j] = matrix[i][j];
        }

        for (int j = 0; j < x_len; j++) {
            matrix[i][j] = temp[x_len - 1 - j];
        }
    }
    free(temp);
}