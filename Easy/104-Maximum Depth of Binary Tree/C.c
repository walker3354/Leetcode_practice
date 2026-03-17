#include <stdlib.h>
typedef struct TreeNode {
        int val;
        struct TreeNode* left;
        struct TreeNode* right;
} TreeNode;

int find_max_number(int a, int b) {
    if (a >= b) return a;
    return b;
}

int find_tree_height(struct TreeNode* node) {
    if (node == NULL) return 0;
    int left_tree_height = find_tree_height(node->left);
    int right_tree_height = find_tree_height(node->right);
    return 1 + find_max_number(left_tree_height, right_tree_height);
}

int maxDepth(struct TreeNode* root) {
    if (root == NULL) return 0;
    return 1 + find_max_number(find_tree_height(root->left),
                               find_tree_height(root->right));
}