#include <stdlib.h>

void search_land(char** grid, int gridSize, int* gridColSize, int** record_map,
                 int pos_x, int pos_y) {
    if (record_map[pos_x][pos_y] == 1) return;
    record_map[pos_x][pos_y] = 1;
    // up
    if (pos_y != 0 && grid[pos_x][pos_y - 1] == '1')
        search_land(grid, gridSize, gridColSize, record_map, pos_x, pos_y - 1);
    // down
    if (pos_y != gridColSize[pos_x] - 1 && grid[pos_x][pos_y + 1] == '1')
        search_land(grid, gridSize, gridColSize, record_map, pos_x, pos_y + 1);
    // left
    if (pos_x != 0 && grid[pos_x - 1][pos_y] == '1')
        search_land(grid, gridSize, gridColSize, record_map, pos_x - 1, pos_y);
    // right
    if (pos_x != gridSize - 1 && grid[pos_x + 1][pos_y] == '1')
        search_land(grid, gridSize, gridColSize, record_map, pos_x + 1, pos_y);
}

int numIslands(char** grid, int gridSize, int* gridColSize) {
    int island_counter = 0;
    int** record_map = (int**)malloc(gridSize * sizeof(int*));
    for (int i = 0; i < gridSize; i++) {
        record_map[i] = (int*)malloc(gridColSize[i] * sizeof(int));
        memset(record_map[i], -1, gridColSize[i] * sizeof(int));
    }

    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[i]; j++) {
            if (record_map[i][j] == 1) continue;
            if (grid[i][j] == '0') {
                record_map[i][j] = 1;
                continue;
            }
            island_counter++;
            search_land(grid, gridSize, gridColSize, record_map, i, j);
        }
    }
    return island_counter;
}