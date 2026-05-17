#include <stdbool.h>
#include <stdlib.h>

struct ListNode {
        int val;
        struct ListNode* next;
};

bool hasCycle(struct ListNode* head) {
    if (head == NULL || head->next == NULL) return false;
    struct ListNode* slow_node = head;
    struct ListNode* fast_node = head;
    while (fast_node->next != NULL && fast_node->next->next != NULL) {
        slow_node = slow_node->next;
        fast_node = fast_node->next->next;
        if (fast_node == slow_node) return true;
    }
    return false;
}