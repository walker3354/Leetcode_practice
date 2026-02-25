#include <vector>

using namespace std;
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
        ListNode* bestsoultion(ListNode* head) {
            if (head == nullptr || head->next == nullptr) return head;

            ListNode* pre = nullptr;
            ListNode* cur = head;
            while (cur != nullptr) {
                ListNode* temp = cur->next;
                cur->next = pre;
                pre = cur;
                cur = temp;
            }
            return pre;
        }

        ListNode* reverseList(ListNode* head) {
            if (head == nullptr || head->next == nullptr) return head;
            ListNode* tail = head;
            while ((tail->next != nullptr)) {
                tail = tail->next;
            }
            while (head != tail) {
                ListNode* temp_node = head->next;
                head->next = tail->next;
                tail->next = head;
                head = temp_node;
            }
            return tail;
        }

        ListNode* bad_method(ListNode* head) {
            if (head == nullptr || head->next == nullptr) return head;
            vector<int> val_temp;
            while (head != nullptr) {
                val_temp.push_back(head->val);
                head = head->next;
            }
            ListNode* new_head = new ListNode(val_temp.back());
            ListNode* temp_head = new_head;
            val_temp.pop_back();
            while (!val_temp.empty()) {
                ListNode* temp_node = new ListNode(val_temp.back());
                val_temp.pop_back();
                temp_head->next = temp_node;
                temp_head = temp_node;
            }
            return new_head;
        }
};