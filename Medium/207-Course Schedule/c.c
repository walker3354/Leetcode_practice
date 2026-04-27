#include <stdbool.h>
#include <stdlib.h>

bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize,
               int* prerequisitesColSize) {
    // 1. 初始化資料結構
    int* inDegree = calloc(numCourses, sizeof(int));

    // adj[i] 是一個陣列，存著「修完課 i 可以解鎖的課」
    // C 語言裡為了方便，常直接給一個夠大的 2D 陣列，或用指標陣列動態給
    // 這裡用一個簡單的陣列陣列模擬，adj[i][0] 存數量，後面存解鎖的課
    int** adj = malloc(numCourses * sizeof(int*));
    for (int i = 0; i < numCourses; i++) {
        // 最壞情況下一堂課可以解鎖所有其他課，所以開 numCourses 大小
        // 第 0 個位置用來存 count
        adj[i] = calloc(numCourses, sizeof(int));
    }

    // 2. 建立 Graph
    for (int i = 0; i < prerequisitesSize; i++) {
        int course = prerequisites[i][0];
        int pre = prerequisites[i][1];

        inDegree[course]++; // course 的先修課數量 +1

        // 修完 pre 可以解鎖 course，把它加進 pre 的解鎖清單
        int count = ++adj[pre][0];
        adj[pre][count] = course;
    }

    // 3. 把所有 inDegree 為 0 的課（不用先修課的）放進 Queue
    int* queue = malloc(numCourses * sizeof(int));
    int head = 0, tail = 0;

    for (int i = 0; i < numCourses; i++) {
        if (inDegree[i] == 0) {
            queue[tail++] = i;
        }
    }

    // 4. 開始修課 (BFS)
    int finishCount = 0;
    while (head < tail) {
        int current = queue[head++]; // 修掉這堂課
        finishCount++;

        // 通知所有它能解鎖的課
        int unlockCount = adj[current][0];
        for (int i = 1; i <= unlockCount; i++) {
            int nextCourse = adj[current][i];
            inDegree[nextCourse]--; // 後續課的先修需求 -1

            // 如果後續課的需求歸零了，代表它可以修了，放進 Queue
            if (inDegree[nextCourse] == 0) {
                queue[tail++] = nextCourse;
            }
        }
    }

    // 5. 釋放記憶體
    for (int i = 0; i < numCourses; i++) free(adj[i]);
    free(adj);
    free(inDegree);
    free(queue);

    // 如果修完的課數等於總課數，代表沒有 Cycle，可以全部修完
    return finishCount == numCourses;
}