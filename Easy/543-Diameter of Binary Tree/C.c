#include <stdlib.h>

struct TreeNode {
        int val;
        struct TreeNode* left;
        struct TreeNode* right;
};

int diameterOfBinaryTree(struct TreeNode* root) {
    if (root == NULL) return 0;
    int left_height = diameterOfBinaryTree(root) + 1;
}