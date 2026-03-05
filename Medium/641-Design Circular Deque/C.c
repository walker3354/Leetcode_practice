#include <stdbool.h>
#include <stdlib.h>

typedef struct DequeNode {
        int value;
        struct DequeNode* next;
        struct DequeNode* prev;
} DequeNode;

typedef struct {
        int node_counter;
        int max_deque_node_num;
        DequeNode* head;
        DequeNode* tail;
} MyCircularDeque;

MyCircularDeque* myCircularDequeCreate(int k) {
    MyCircularDeque* circular_deque = malloc(sizeof(MyCircularDeque));
    circular_deque->head = NULL;
    circular_deque->tail = NULL;
    circular_deque->node_counter = 0;
    circular_deque->max_deque_node_num = k;
    return circular_deque;
}

bool myCircularDequeInsertFront(MyCircularDeque* obj, int value) {
    if (obj->node_counter == obj->max_deque_node_num) return false;

    DequeNode* temp_node = malloc(sizeof(DequeNode));
    temp_node->value = value;
    if (obj->node_counter == 0) {
        temp_node->prev = NULL;
        temp_node->next = NULL;
        obj->head = temp_node;
        obj->tail = temp_node;
    } else {
        temp_node->next = obj->head;
        temp_node->prev = NULL;
        obj->head->prev = temp_node;
        obj->head = temp_node;
    }
    obj->node_counter++;
    return true;
}

bool myCircularDequeInsertLast(MyCircularDeque* obj, int value) {
    if (obj->node_counter == obj->max_deque_node_num) return false;

    DequeNode* temp_node = malloc(sizeof(DequeNode));
    temp_node->value = value;
    if (obj->node_counter == 0) {
        temp_node->prev = NULL;
        temp_node->next = NULL;
        obj->head = temp_node;
        obj->tail = temp_node;
    } else {
        temp_node->prev = obj->tail;
        temp_node->next = NULL;
        obj->tail->next = temp_node;
        obj->tail = temp_node;
    }
    obj->node_counter++;
    return true;
}

bool myCircularDequeDeleteFront(MyCircularDeque* obj) {
    if (obj->node_counter == 0) return false;
    if (obj->node_counter == 1) {
        free(obj->head);
        obj->head = NULL;
        obj->tail = NULL;
    } else {
        DequeNode* temp_node = obj->head->next;
        free(obj->head);
        temp_node->prev = NULL;
        obj->head = temp_node;
    }
    obj->node_counter -= 1;
    return true;
}

bool myCircularDequeDeleteLast(MyCircularDeque* obj) {
    if (obj->node_counter == 0) return false;
    if (obj->node_counter == 1) {
        free(obj->tail);
        obj->tail = NULL;
        obj->head = NULL;
    } else {
        DequeNode* temp_node = obj->tail->prev;
        temp_node->next = NULL;
        free(obj->tail);
        obj->tail = temp_node;
    }
    obj->node_counter -= 1;
    return true;
}

int myCircularDequeGetFront(MyCircularDeque* obj) {
    if (obj->node_counter == 0) return -1;
    return obj->head->value;
}

int myCircularDequeGetRear(MyCircularDeque* obj) {
    if (obj->node_counter == 0) return -1;
    return obj->tail->value;
}

bool myCircularDequeIsEmpty(MyCircularDeque* obj) {
    if (obj->node_counter == 0) return true;
    return false;
}

bool myCircularDequeIsFull(MyCircularDeque* obj) {
    if (obj->node_counter == obj->max_deque_node_num) return true;
    return false;
}

void myCircularDequeFree(MyCircularDeque* obj) {
    while (obj->head != NULL) {
        DequeNode* temp_node = obj->head->next;
        free(obj->head);
        obj->head = temp_node;
    } // head = tail = NULL
    free(obj);
}

/**
 * Your MyCircularDeque struct will be instantiated and called as such:
 * MyCircularDeque* obj = myCircularDequeCreate(k);
 * bool param_1 = myCircularDequeInsertFront(obj, value);

 * bool param_2 = myCircularDequeInsertLast(obj, value);

 * bool param_3 = myCircularDequeDeleteFront(obj);

 * bool param_4 = myCircularDequeDeleteLast(obj);

 * int param_5 = myCircularDequeGetFront(obj);

 * int param_6 = myCircularDequeGetRear(obj);

 * bool param_7 = myCircularDequeIsEmpty(obj);

 * bool param_8 = myCircularDequeIsFull(obj);

 * myCircularDequeFree(obj);
*/