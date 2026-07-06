#include <stdlib.h>
// Definition for singly-linked list.
struct ListNode {
        int val;
        struct ListNode* next;
};

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;

    struct ListNode* dummy_head = malloc(sizeof(struct ListNode));
    struct ListNode* insert_pos = dummy_head;

    while (list1 != NULL && list2 != NULL) {
        if (list1->val <= list2->val) {
            insert_pos->next = list1;
            list1 = list1->next;
        } else {
            insert_pos->next = list2;
            list2 = list2->next;
        }
        insert_pos = insert_pos->next;
    }

    if (list1 == NULL) insert_pos->next = list2;
    if (list2 == NULL) insert_pos->next = list1;
    struct ListNode* result = dummy_head->next;
    free(dummy_head);
    return result;
}