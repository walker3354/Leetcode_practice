#include <stdlib.h>

int* dailyTemperatures(int* temperatures, int temperaturesSize,
                       int* returnSize) {
    if (temperaturesSize <= 0) {
        *returnSize = 0;
        return NULL;
    }

    int* result = calloc(temperaturesSize, sizeof(int));
    int* stack = malloc(temperaturesSize * sizeof(int)); // [] = index
    int counter = -1;
    *returnSize = temperaturesSize;

    for (int i = 0; i < temperaturesSize; i++) {
        while (counter >= 0 && temperatures[stack[counter]] < temperatures[i]) {
            result[stack[counter]] = i - stack[counter];
            counter--;
        }
        stack[++counter] = i;
    }

    free(stack);
    return result;
}