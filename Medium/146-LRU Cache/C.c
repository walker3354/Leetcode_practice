#include <stdlib.h>

typedef struct Node {
        int key;
        int value;
        struct Node* pre;
        struct Node* next;
} Node;

typedef struct {
        int capacity;
        int node_counter;
        Node* hashtable[10001];
        Node* head; // new->old->oldest
        Node* tail;
} LRUCache;

LRUCache* lRUCacheCreate(int capacity) {
    LRUCache* temp = malloc(sizeof(LRUCache));
    temp->capacity = capacity;
    temp->node_counter = 0;
    memset(temp->hashtable, 0, sizeof(temp->hashtable)); // all set 0(NULL)
    temp->head = NULL;
    temp->tail = NULL;
    return temp;
}

int lRUCacheGet(LRUCache* obj, int key) {
    if (obj->node_counter == 0 || obj->hashtable[key] == NULL) {
        return -1;
    } else if (obj->node_counter == 1 || obj->head == obj->hashtable[key]) {
        return obj->hashtable[key]->value;
    }

    Node* pre_temp = obj->hashtable[key]->pre;
    Node* next_temp = obj->hashtable[key]->next;
    pre_temp->next = next_temp;
    if (next_temp != NULL) {
        next_temp->pre = pre_temp; 
    } else {
        obj->tail = pre_temp; 
    }
    obj->head->pre = obj->hashtable[key];
    obj->hashtable[key]->next = obj->head;
    obj->head = obj->hashtable[key];
    obj->head->pre = NULL;
    return obj->head->value;
}
void lRUCachePut(LRUCache* obj, int key, int value) {
    if (obj->hashtable[key] != NULL) { // already exsist
        obj->hashtable[key]->value = value;
        lRUCacheGet(obj, key);
    } else if (obj->node_counter == obj->capacity) {
        if (obj->capacity == 1) {
            obj->hashtable[obj->head->key] = NULL;
            obj->hashtable[key] = obj->head;
            obj->head->value = value;
            obj->head->key = key;
        } else {
            int temp_tail_key = obj->tail->key;
            Node* temp_tail = obj->tail->pre;
            Node* temp_node = malloc(sizeof(Node));
            temp_node->value = value;
            temp_node->key = key;
            obj->hashtable[key] = temp_node;

            free(obj->tail);
            obj->hashtable[temp_tail_key] = NULL;
            obj->tail = temp_tail;
            temp_tail->next = NULL;
            temp_node->next = obj->head;
            obj->head->pre = temp_node;
            temp_node->pre = NULL;
            obj->head = temp_node;
            obj->hashtable[key] = temp_node;
        }
    } else { // not full
        obj->node_counter++;
        Node* temp_node = malloc(sizeof(Node));
        temp_node->key = key;
        temp_node->value = value;
        temp_node->pre = NULL;

        if (obj->node_counter == 1) {
            obj->tail = temp_node;
            temp_node->next = NULL;
        } else {
            temp_node->next = obj->head;
            obj->head->pre = temp_node;
        }
        obj->head = temp_node;
        obj->hashtable[key] = temp_node;
    }
}

void lRUCacheFree(LRUCache* obj) {
    while (obj->head != NULL) {
        Node* temp_node = obj->head;
        obj->head = obj->head->next;
        free(temp_node);
    }
    free(obj);
}

/**
 * Your LRUCache struct will be instantiated and called as such:
 * LRUCache* obj = lRUCacheCreate(capacity);
 * int param_1 = lRUCacheGet(obj, key);

 * lRUCachePut(obj, key, value);

 * lRUCacheFree(obj);
*/