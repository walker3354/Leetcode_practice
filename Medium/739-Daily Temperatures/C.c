#include <stdlib.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct node {
        struct node* prev;
        struct node* next;
        int index;
        int temperature;
} node;

int* dailyTemperatures(int* temperatures, int temperaturesSize,
                       int* returnSize) {
    if (temperaturesSize <= 0) {
        *returnSize = 0;
        return NULL;
    }

    int* result = malloc(temperaturesSize * sizeof(int));
    *returnSize = temperaturesSize;

    node* head = malloc(sizeof(node));
    node* tail = malloc(sizeof(node));
    head->prev = NULL;
    head->next = tail;
    tail->next = NULL;
    tail->prev = head;

    for (int i = 0; i < temperaturesSize; i++) {
        if (tail->prev == head) {
            node* temp = malloc(sizeof(node));
            temp->index = i;
            temp->temperature = temperatures[i];
            head->next = temp;
            temp->prev = head;
            temp->next = tail;
            tail->prev = temp;
        } else {
            while (tail->prev != head &&
                   tail->prev->temperature < temperatures[i]) {
                node* temp_node = tail->prev;
                result[temp_node->index] = i - temp_node->index;
                temp_node->prev->next = tail;
                tail->prev = temp_node->prev;
                free(temp_node);
            }
            node* temp = malloc(sizeof(node));
            temp->index = i;
            temp->temperature = temperatures[i];
            temp->prev = tail->prev;
            tail->prev->next = temp;
            tail->prev = temp;
            temp->next = tail;
        }
    }

    node* temp = head->next;
    while (temp != NULL) {
        if (temp != tail) {
            result[temp->index] = 0;
        }
        node* next_node = temp->next;
        free(temp);
        temp = next_node;
    }
    free(head);
    return result;
}