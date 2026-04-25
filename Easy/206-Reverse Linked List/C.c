#include <stdlib.h>

struct ListNode {
        int val;
        struct ListNode* next;
};

struct ListNode* reverseList(struct ListNode* head) {
    if (head == NULL) return NULL;
    struct ListNode* prev = NULL;
    struct ListNode* next = head;

    while (next != NULL) {
        struct ListNode* temp = next->next;
        next->next = prev;
        prev = next;
        next = temp;
    }
    return prev;
}