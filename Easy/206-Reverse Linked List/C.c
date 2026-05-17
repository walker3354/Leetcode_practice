#include <stdlib.h>

struct ListNode {
        int val;
        struct ListNode* next;
};

struct ListNode* reverseList(struct ListNode* head) {
    if (head == NULL) return NULL;
    struct ListNode* temp = NULL;
    while (head != NULL) {
        struct ListNode* next_temp = head->next;
        head->next = temp;
        temp = head;
        head = next_temp;
    }
    return temp;
}