#include <stdlib.h>

int swap(const void* a, const void* b) {
    int* ia = *(int**)a;
    int* ib = *(int**)b;
    if (ia[0] > ib[0]) return 1;
    if (ia[0] < ib[0]) return -1;
    return 0;
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize,
            int* returnSize, int** returnColumnSizes) {
    qsort(intervals, intervalsSize, sizeof(int*), swap);

    int result_counter = 0;
    int** result = (int**)malloc(intervalsSize * sizeof(int*));
    for (int i = 0; i < intervalsSize; i++) {
        result[i] = (int*)malloc(2 * sizeof(int));
    }

    result[0][0] = intervals[0][0];
    result[0][1] = intervals[0][1];

    for (int i = 1; i < intervalsSize; i++) {
        int next_begin = intervals[i][0];
        int next_end = intervals[i][1];
        if (next_begin <= result[result_counter][1]) {
            if (next_end > result[result_counter][1]) {
                result[result_counter][1] = next_end;
            }
        } else {
            result_counter++;
            result[result_counter][0] = next_begin;
            result[result_counter][1] = next_end;
        }
    }

    result_counter++;
    *returnSize = result_counter;

    *returnColumnSizes = (int*)malloc(result_counter * sizeof(int));
    for (int i = 0; i < result_counter; i++) {
        (*returnColumnSizes)[i] = 2;
    }

    return result;
}
