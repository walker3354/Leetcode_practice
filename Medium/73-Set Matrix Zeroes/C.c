void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
    if (matrixSize <= 0) return;
    int cols = matrixColSize[0];
    int firstColZero = 0; // overlap [1,0][1,1] => [0,0][1,1]

    for (int i = 0; i < matrixSize; i++) {
        if (matrix[i][0] == 0) {
            firstColZero = 1;
        }
        for (int j = 1; j < cols; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    for (int i = 1; i < matrixSize; i++) {
        for (int j = 1; j < cols; j++) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }

    if (matrix[0][0] == 0) {
        for (int j = 0; j < cols; j++) {
            matrix[0][j] = 0;
        }
    }

    if (firstColZero) {
        for (int i = 0; i < matrixSize; i++) {
            matrix[i][0] = 0;
        }
    }
}