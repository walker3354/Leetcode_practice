#include <stdio.h>
#include <stdlib.h>

void printPyramid(int n) { // height
    for (int i = 0; i < n ; i++) {
        for (int j = n - 2 - i; j >= 0; j--) {
            printf(" ");
        }

        printf("*");
        for (int j = 0; j < i; j++) {
            printf("**");
        }
        printf("\n");
    }
}