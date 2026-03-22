#include <stdlib.h>

// input range 0<= input <= 10000

range = 10001;

typedef struct Cache_Node {
        struct Cache_Node* prev;
        struct Cache_Node* next;
        int value;
        int key;
} Cache_Node;

typedef struct {
        Cache_Node* head;
        Cache_Node* tail;
        Cache_Node** node_map;

        int max_capacity;
        int node_counter;
} LRUCache;

LRUCache* lRUCacheCreate(int capacity) {
    LRUCache* cache = malloc(sizeof(LRUCache));

    cache->head = malloc(sizeof(Cache_Node));
    cache->tail = malloc(sizeof(Cache_Node));
    cache->node_map = calloc(range, sizeof(Cache_Node*));

    cache->max_capacity = capacity;
    cache->node_counter = 0;
    cache->head->next = cache->tail;
    cache->head->prev = NULL;
    cache->tail->prev = cache->head;
    cache->tail->next = NULL;
    return cache;
}

void connect_nodes(LRUCache* obj, int key) {
    Cache_Node* temp_node = obj->node_map[key]->prev;
    obj->node_map[key]->next->prev = temp_node;
    temp_node->next = obj->node_map[key]->next;
}

void add_to_head(LRUCache* obj, Cache_Node* node) {
    node->next = obj->head->next;
    node->prev = obj->head;
    obj->head->next->prev = node;
    obj->head->next = node;
}

// 讀取 key 的值。如果 key 存在，回傳
// value，並將此節點更新為「最近使用」；否則回傳 -1
int lRUCacheGet(LRUCache* obj, int key) {
    if (obj->node_map[key] == NULL) return -1;
    if (obj->node_counter == 1) return obj->node_map[key]->value;

    connect_nodes(obj, key);
    add_to_head(obj, obj->node_map[key]);
    return obj->node_map[key]->value;
}

// 寫入 key 與 value。
// 如果 key 已存在，更新 value，並將其設為「最近使用」。
// 如果 key 不存在，插入該組 key-value。
// 若插入後超過 capacity，則必須剔除「最久未使用（Least Recently
// Used）」的節點。
void lRUCachePut(LRUCache* obj, int key, int value) {
    if (obj->node_map[key] != NULL) {
        lRUCacheGet(obj, key);
        obj->node_map[key]->value = value;
        return;
    }

    Cache_Node* new_node = malloc(sizeof(Cache_Node));
    new_node->value = value;
    new_node->key = key;
    obj->node_map[key] = new_node;
    add_to_head(obj, new_node);
    if (obj->node_counter == obj->max_capacity) {
        int temp_key = obj->tail->prev->key;
        connect_nodes(obj, temp_key);
        free(obj->node_map[temp_key]);
        obj->node_map[temp_key] = NULL;
        return;
    }
    obj->node_counter++;
}

void lRUCacheFree(LRUCache* obj) {
    while (obj->head != obj->tail) {
        Cache_Node* temp_node = obj->head;
        obj->head = obj->head->next;
        free(temp_node);
    }
    free(obj->tail);
    free(obj->node_map);
    free(obj);
}