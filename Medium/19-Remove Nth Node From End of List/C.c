#include <stdlib.h>
struct ListNode {
        int val;
        struct ListNode* next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* first_node = head;
    struct ListNode* second_node = head;
    for (int i = 0; i < n; i++) {
        first_node = first_node->next;
    }
    if (first_node == NULL) {
        second_node = second_node->next;
        free(head);
        return second_node;
    }
    while (first_node->next != NULL) {
        first_node = first_node->next;
        second_node = second_node->next;
    }
    struct ListNode* temp_node = second_node->next;
    second_node->next = temp_node->next;
    free(temp_node);
    return head;
}