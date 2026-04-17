#include <stdbool.h>
#include <stdlib.h>

struct ListNode {
        int val;
        struct ListNode* next;
};

struct ListNode* detectCycle(struct ListNode* head) {
    if (head == NULL) return NULL;
    struct ListNode* left = head;
    struct ListNode* right = head;
    while (right != NULL && right->next != NULL) {
        right = right->next->next;
        left = left->next;
        if (right == left) {
            left = head;
            while (left != right) {
                left = left->next;
                right = right->next;
            }
            return left;
        }
    }
    return NULL;
}