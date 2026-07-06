#include <stdlib.h>

struct ListNode {
        int val;
        struct ListNode* next;
};

struct ListNode* reverseList(struct ListNode* head) {
    if (head == NULL) return NULL;
    struct ListNode* temp = NULL;

    while (head != NULL) {
        struct ListNode* next = head->next;
        head->next = temp;
        temp = head;
        head = next;
    }
    return temp;
}