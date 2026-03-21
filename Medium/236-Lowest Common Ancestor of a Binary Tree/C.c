#include <stdlib.h>

struct TreeNode {
        int val;
        struct TreeNode* left;
        struct TreeNode* right;
};

struct TreeNode* find_node(struct TreeNode* node, struct TreeNode* p,
                           struct TreeNode* q) {
    if (node == NULL) return NULL;
    struct TreeNode* left_result = find_node(node->left, p, q);
    struct TreeNode* right_result = find_node(node->right, p, q);
    if (node == p || node == q) {
        return node;
    }
    if (left_result != NULL && right_result != NULL) return node;
    if (left_result != NULL) return left_result;
    if (right_result != NULL) return right_result;
    return NULL;
}

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p,
                                      struct TreeNode* q) {
    if (root == NULL) return NULL;
    if (root == p) return p;
    if (root == q) return q;
    return find_node(root, p, q);
}