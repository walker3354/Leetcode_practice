#include <stdlib.h>

struct ListNode {
        int val;
        struct ListNode* next;
};

struct ListNode* reverseList(struct ListNode* head) {
    if (head == NULL) return NULL;
    struct ListNode* temp = NULL;
    struct ListNode* cur = head;
    while (cur != NULL) {
        struct ListNode* next_node = cur->next;
        cur->next = temp;
        temp = cur;
        cur = next_node;
    }
    return temp;
}