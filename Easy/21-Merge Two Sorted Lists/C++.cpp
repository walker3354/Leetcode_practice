/**
 * Definition for singly-linked list.
 *
 */
class Solution {
    private:
        struct ListNode {
                int val;
                ListNode* next;
                ListNode() : val(0), next(nullptr) {}
                ListNode(int x) : val(x), next(nullptr) {}
                ListNode(int x, ListNode* next) : val(x), next(next) {}
        };

    public:
        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
            if (list1 == nullptr) return list2;
            if (list2 == nullptr) return list1;
            ListNode new_head(0);
            ListNode* cur_node = &new_head;
            while (list1 != nullptr && list2 != nullptr) {
                if (list1->val <= list2->val) {
                    cur_node->next = list1;
                    list1 = list1->next;
                } else {
                    cur_node->next = list2;
                    list2 = list2->next;
                }
                cur_node = cur_node->next;
            }
            if (list1 == nullptr) {
                cur_node->next = list2;
            } else {
                cur_node->next = list1;
            }
            return new_head.next;
        }
};