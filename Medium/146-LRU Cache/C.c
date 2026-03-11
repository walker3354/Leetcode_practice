#include <stdbool.h>
#include <stdlib.h>

typedef struct Node {
        int key;
        Node* pre;
        Node* next;
} Node;

typedef struct {
        int capacity;
        int node_counter;
        int value[10001];
        Node* hashtable[10001];
        Node* head;
        Node* tail;
} LRUCache;

LRUCache* lRUCacheCreate(int capacity) {
    LRUCache* temp = malloc(sizeof(LRUCache));
    temp->capacity = capacity;
    temp->node_counter = 0;
    return temp;
}

int lRUCacheGet(LRUCache* obj, int key) {}

void lRUCachePut(LRUCache* obj, int key, int value) {}

void lRUCacheFree(LRUCache* obj) {}

/**
 * Your LRUCache struct will be instantiated and called as such:
 * LRUCache* obj = lRUCacheCreate(capacity);
 * int param_1 = lRUCacheGet(obj, key);

 * lRUCachePut(obj, key, value);

 * lRUCacheFree(obj);
*/