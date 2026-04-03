#include <stdbool.h>
#include <stdlib.h>

// 0:empth. 1:fresh. 2:rotten

bool check_fresh_fruit(int** grid, int gridSize, int* gridColSize) {
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[i]; j++) {
            if (grid[i][j] == 1) return true;
        }
    }
    return false; // no fresh
}

int get_rotten_fruit(int** grid, int gridSize, int* gridColSize, int* x_pos,
                     int* y_pos) {
    int counter = 0;
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[i]; j++) {
            if (grid[i][j] == 2) {
                y_pos[counter] = i;
                x_pos[counter] = j;
                counter++;
            }
        }
    }
    return counter;
}

int orangesRotting(int** grid, int gridSize, int* gridColSize) {
    if (gridSize <= 0) return 0;
    int total_space = gridSize * gridColSize[0];
    int* x_pos = malloc(total_space * sizeof(int));
    int* y_pos = malloc(total_space * sizeof(int));
    memset(x_pos, -1, gridColSize[0] * sizeof(int));
    memset(y_pos, -1, gridSize);
    int left = 0,
        right = get_rotten_fruit(grid, gridSize, gridColSize, x_pos, y_pos);
    int step = 0;
    while (left < right) {
        // find left
        int interval = right;
        for (int i = left; i < interval; i++) {
            if (x_pos[i] > 0 && grid[y_pos[i]][x_pos[i] - 1] == 1) {
                grid[y_pos[i]][x_pos[i] - 1] = 2;
                y_pos[right] = y_pos[i];
                x_pos[right] = x_pos[i] - 1;
                right++;
            }
            // find right
            if (x_pos[i] < gridColSize[y_pos[i]] - 1 &&
                grid[y_pos[i]][x_pos[i] + 1] == 1) {
                grid[y_pos[i]][x_pos[i] + 1] = 2;
                y_pos[right] = y_pos[i];
                x_pos[right] = x_pos[i] + 1;
                right++;
            }
            // find up
            if (y_pos[i] > 0 && grid[y_pos[i] - 1][x_pos[i]] == 1) {
                grid[y_pos[i] - 1][x_pos[i]] = 2;
                y_pos[right] = y_pos[i] - 1;
                x_pos[right] = x_pos[i];
                right++;
            }
            // find down
            if (y_pos[i] < gridSize - 1 && grid[y_pos[i] + 1][x_pos[i]] == 1) {
                grid[y_pos[i] + 1][x_pos[i]] = 2;
                y_pos[right] = y_pos[i] + 1;
                x_pos[right] = x_pos[i];
                right++;
            }
        }
        left = interval;
        if (left < right) step++;
    }
    free(x_pos);
    free(y_pos);
    return check_fresh_fruit(grid, gridSize, gridColSize) ? -1 : step;
}