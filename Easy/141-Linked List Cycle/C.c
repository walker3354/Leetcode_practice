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

#define FAN_PRESENT (1 << 0)
#define FAN_FAULT (1 << 1)
#define FAN_PWM_EN (1 << 2)
#define FAN_FULLSPD (1 << 3)

int update_fan_status(int status, int rpm, int temp) {
    if (rpm == 0) {
        status |= FAN_FAULT;
    }
    if (temp > 80) {
        status |= FAN_FULLSPD;
    }

    if (temp < 60) {
        status &= ~FAN_FULLSPD;
    }

    return status;
}