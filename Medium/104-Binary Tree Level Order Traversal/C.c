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

int find_tree_height(struct TreeNode* root) {
    if (root == NULL) return 0;
    return fmax(find_tree_height(root->left), find_tree_height(root->right)) +
           1;
}

int** levelOrder(struct TreeNode* root, int* returnSize,
                 int** returnColumnSizes) {
    if (root == NULL) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }
    *returnSize = find_tree_height(root);
    int** result = malloc(*returnSize * sizeof(int*));
    returnColumnSizes = malloc(*returnSize * sizeof(int*));

    int front = 0, tail = 0, level_counter = 0;
    struct TreeNode** queue = malloc(2000 * sizeof(struct TreeNode*));
    queue[tail++] = root;

    while (front < tail) {
        int level_node_num = tail - front;
        result[level_counter] = malloc(level_node_num * sizeof(int));
        (*returnColumnSizes)[level_counter] = level_node_num;

        for (int i = 0; i < level_node_num; i++) {
            result[level_counter][i] = queue[front]->val;
            if (queue[front]->left != NULL) queue[tail++] = queue[front]->left;
            if (queue[front]->right != NULL)
                queue[tail++] = queue[front]->right;
            front++;
        }
        level_counter++;
    }
    return result;
}