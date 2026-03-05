#include <stdbool.h>
#include <stdlib.h>

typedef struct {
        int* buffer;
        int head;
        int tail;
        int size; // how many element
        int dequeue_max_size;
} MyCircularDeque;

MyCircularDeque* myCircularDequeCreate(int k) {
    MyCircularDeque* circular_deque = malloc(sizeof(MyCircularDeque));
    circular_deque->buffer = malloc(k * sizeof(int));
    circular_deque->dequeue_max_size = k;
    circular_deque->size = 0;
    circular_deque->head = 0;
    circular_deque->tail = 0;
    return circular_deque;
}

bool myCircularDequeInsertFront(MyCircularDeque* obj, int value) {
    if (obj->size >= obj->dequeue_max_size) return false;

    obj->head = (obj->head - 1 + obj->dequeue_max_size) % obj->dequeue_max_size;
    *(obj->buffer + obj->head) = value;
    obj->size++;
    return true;
}

bool myCircularDequeInsertLast(MyCircularDeque* obj, int value) {
    if (obj->size >= obj->dequeue_max_size) return false;

    *(obj->buffer + obj->tail) = value;
    obj->tail = (obj->tail + 1) % obj->dequeue_max_size;
    obj->size++;
    return true;
}

bool myCircularDequeDeleteFront(MyCircularDeque* obj) {
    if (obj->size == 0) return false;
    obj->head = (obj->head + 1) % obj->dequeue_max_size;
    obj->size--;
    return true;
}

bool myCircularDequeDeleteLast(MyCircularDeque* obj) {
    if (obj->size == 0) return false;
    obj->tail = (obj->tail - 1 + obj->dequeue_max_size) % obj->dequeue_max_size;
    obj->size--;
    return true;
}

int myCircularDequeGetFront(MyCircularDeque* obj) {
    if (obj->size == 0 || obj == NULL) return -1;
    return *(obj->buffer + obj->head);
}

int myCircularDequeGetRear(MyCircularDeque* obj) {
    if (obj->size == 0 || obj == NULL) return -1;
    return *(obj->buffer +
             ((obj->tail - 1 + obj->dequeue_max_size) % obj->dequeue_max_size));
}

bool myCircularDequeIsEmpty(MyCircularDeque* obj) {
    if (obj->size == 0) return true;
    return false;
}

bool myCircularDequeIsFull(MyCircularDeque* obj) {
    if (obj->size == obj->dequeue_max_size) return true;
    return false;
}

void myCircularDequeFree(MyCircularDeque* obj) {
    if (obj == NULL) return;
    free(obj->buffer);
    free(obj);
}
