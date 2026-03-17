#include <stdlib.h>

struct TreeNode {
        int val;
        struct TreeNode* left;
        struct TreeNode* right;
};

struct TreeNode* invertTree(struct TreeNode* root) {
    if (root == NULL) return NULL;

    struct TreeNode* temp_node = invertTree(root->left);
    invertTree(root->right);
    root->left = root->right;
    root->right = temp_node;
    return root;
}