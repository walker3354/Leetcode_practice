#include <stdbool.h>
#include <stdlib.h>

bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize,
               int* prerequisitesColSize) {
    if (prerequisitesSize <= 0 || numCourses <= 0) return true;

    // course_req_counter[course_ID] = req_num
    int* course_req_counter = calloc(numCourses, sizeof(int));
    //[course_ID][0] = course_counter [course_ID][]
    int** req_course_recordd = malloc(numCourses * sizeof(int*));

    for (int i = 0; i < prerequisitesSize; i++) {
        req_course_recordd[i] = malloc(sizeof(numCourses) * sizeof(int));
    }

    for (int i = 0; i < prerequisitesSize; i++) {
        int req_course_ID = prerequisites[i][1];
        int unlock_course = prerequisites[i][0];
        course_req_counter[unlock_course]++;

        int count = ++req_course_recordd[req_course_ID][0];
        req_course_recordd[req_course_ID][count] = unlock_course;
    }

    int* queue = malloc(numCourses * sizeof(int));
    int head = 0, tail = 0;

    for (int i = 0; i < numCourses; i++) {
        if (course_req_counter[i] == 0) {
            queue[tail++] = i;
        }
    }

    int finishCount = 0;
    while (head < tail) {
        int current = queue[head++]; // 修掉這堂課
        finishCount++;
        int unlockCount = req_course_recordd[current][0];
        for (int i = 1; i <= unlockCount; i++) {
            int nextCourse = req_course_recordd[current][i];
            course_req_counter[nextCourse]--;
            if (course_req_counter[nextCourse] == 0) {
                queue[tail++] = nextCourse;
            }
        }
    }

    free(queue);
    free(course_req_counter);
    free(req_course_recordd);
    return finishCount == numCourses;
}