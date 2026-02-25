#include <iostream>
#include <set>
using namespace std;

class Solution {
    private:
        struct ListNode {
                int val;
                ListNode* next;
                ListNode(int x) : val(x), next(NULL) {}
        };

    public:
        bool hasCycle(ListNode* head) {
            if (head == NULL || head->next == NULL) return false;
            int faster_scale = 2;
            ListNode* fast_ptr = head;
            ListNode* slow_ptr = head;
            while (true) {
                for (int i = 0; i < faster_scale; i++) {
                    fast_ptr = fast_ptr->next;
                    if (fast_ptr == NULL) return false;
                    if (fast_ptr == slow_ptr) return true;
                }
                slow_ptr = slow_ptr->next;
            }
        }

        bool bad_method(ListNode* head) {
            if (head == NULL || head->next == NULL) return false;
            ListNode* cur_node = head;
            set<ListNode*> node_ptrs; // Hash maybe better(faster)?
            while (cur_node != NULL) {
                if (node_ptrs.count(cur_node) != 0) return true;
                node_ptrs.insert(cur_node);
                cur_node = cur_node->next;
            }
            return false;
        }
};