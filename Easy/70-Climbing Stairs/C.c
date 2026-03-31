#include <stdlib.h>

int climbStairs(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;

    int tail = 1, prev = 1;
    for (int i = 1; i < n; i++) {
        int temp = tail + prev;
        tail = prev;
        prev = temp;
    }
    return prev;
}