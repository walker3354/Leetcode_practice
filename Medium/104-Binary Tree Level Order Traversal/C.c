#include <math.h>
#include <stdlib.h>

struct TreeNode {
        int val;
        struct TreeNode* left;
        struct TreeNode* right;
};

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */

typedef struct queue_node {
        struct TreeNode* tree_node;
        struct queue_node* prev;
        struct queue_node* next;
} queue_node;

typedef struct queue {
        queue_node* head;
        queue_node* tail;
        int node_count;
} queue;

void insert_node(queue* queue, queue_node* node) { // push back
    queue_node* temp_node = queue->tail->prev;
    temp_node->next = node;
    queue->tail->prev = node;
    node->prev = temp_node;
    node->next = queue->tail;
    queue->node_count++;
}

void remove_node(queue* queue) { // delete front
    if (queue->head->next == queue->tail) return;
    queue_node* temp_node = queue->head->next;
    queue->head->next = temp_node->next;
    temp_node->next->prev = temp_node->prev;
    free(temp_node);
}

int find_tree_height(struct TreeNode* root, int height_counter) {
    if (root == NULL) return height_counter;
    height_counter += 1;
    return fmax(find_tree_height(root->left, height_counter),
                find_tree_height(root->right, height_counter));
}

int** levelOrder(struct TreeNode* root, int* returnSize,
                 int** returnColumnSizes) {
    if (root == NULL) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }

    returnSize = malloc(find_tree_height(root, 0) * sizeof(int));
    returnColumnSizes = malloc(*returnSize * sizeof(int*));
    int** result = malloc(*returnSize * sizeof(int*));

    queue* temp_queue = malloc(sizeof(queue));
    temp_queue->head = malloc(sizeof(queue_node));
    temp_queue->tail = malloc(sizeof(queue_node));
    temp_queue->head->prev = NULL;
    temp_queue->head->next = temp_queue->tail;
    temp_queue->tail->next = NULL;
    temp_queue->tail->prev = temp_queue->head;

    queue_node* first_node = malloc(sizeof(queue_node));
    first_node->tree_node = root;
    insert_node(temp_queue, first_node);

    int column_counter = 0;
    while (temp_queue->node_count != 0) {
        returnColumnSizes[column_counter] =
            malloc(temp_queue->node_count * sizeof(int));
        queue_node* temp_node = temp_queue->head->next;

        int temp_node_counter = temp_queue->node_count;
        temp_queue->node_count = 0;

        for (int i = 0; i < temp_node_counter; i++) {
            if (temp_node->tree_node == NULL) {
                result[column_counter][i] = 0;
            } else {
                result[column_counter][i] = temp_node->tree_node->val;
                queue_node* left_node = malloc(sizeof(queue_node));
                queue_node* right_node = malloc(sizeof(queue_node));
                left_node->tree_node = temp_node->tree_node->left;
                right_node->tree_node = temp_node->tree_node->right;
                insert_node(temp_queue, left_node);
                insert_node(temp_queue, left_node);
            }
        }

        for (int i = 0; i < temp_node_counter; i++) {
            remove_node(temp_queue);
        }
        column_counter + 1;
    }
    queue_node* temp_node = temp_queue->head;
    while (temp_node != NULL) {
        queue_node* next_node = temp_node->next;
        free(temp_node);
        temp_node = next_node;
    }
    free(temp_queue);
    return result;
}