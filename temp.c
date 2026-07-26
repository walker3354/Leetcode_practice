#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void to_uppercase(char* str) {
    if (str == NULL) return;
    int s_len = strlen(str);
    for (int i = 0; i < s_len; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] -= ('a' - 'A');
        }
    }
}

void to_lowercase(char* str) {
    if (str == NULL) return;
    int s_len = strlen(str);
    for (int i = 0; i < s_len; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] += ('a' - 'A');
        }
    }
}

typedef struct List {
        char name[32];
        struct List* next;
} List;

List* remove_nodes(List* head, const char* target) {
    if (head == NULL) return NULL;

    while (head != NULL && strcmp(head->name, target) == 0) {
        List* deleted_node = head;
        head = head->next;
        free(deleted_node);
    }

    List* temp = head;
    while (temp != NULL && temp->next != NULL) {
        if (strcmp(temp->next->name, target) == 0) {
            List* deleted_node = temp->next;
            temp->next = deleted_node->next;
            free(deleted_node);
        } else {
            temp = temp->next;
        }
    }
    return head;
}

int array_to_uint32(uint8_t* arr, size_t len, uint32_t* result) {
    if (len > 4 || arr == NULL || result == NULL) return -1;
    for (int i = 0; i < len; i++) {
        *result |= (*arr << i * 8);
    }
    return 0;
}

int main() {}
