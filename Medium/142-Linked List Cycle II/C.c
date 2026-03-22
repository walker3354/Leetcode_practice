#include <stdbool.h>
#include <stdlib.h>

struct ListNode {
        int val;
        struct ListNode* next;
};

struct ListNode* detectCycle(struct ListNode* head) {
    if (head == NULL) return NULL;

    bool cross_flag = false;
    struct ListNode* fast_node = head;
    struct ListNode* slow_node = head;
    while (fast_node != NULL && fast_node->next != NULL) {
        slow_node = slow_node->next;
        fast_node = fast_node->next->next;
        if (fast_node == slow_node) {
            fast_node = head;
            while (slow_node != fast_node) {
                slow_node = slow_node->next;
                fast_node = fast_node->next;
            }
            return slow_node;
        }
    }
    return NULL;
}