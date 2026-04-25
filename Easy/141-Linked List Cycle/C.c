#include <stdbool.h>
#include <stdlib.h>

struct ListNode {
        int val;
        struct ListNode* next;
};

bool hasCycle(struct ListNode* head) {
    if (head == NULL) return false;
    struct ListNode* left = head;
    struct ListNode* right = head;

    while (right != NULL && right->next != NULL) {
        left = left->next;
        right = right->next->next;
        if (right == left) return true;
    }
    return false;
}