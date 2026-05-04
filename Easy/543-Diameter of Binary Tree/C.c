#include <stdlib.h>
struct TreeNode {
        int val;
        struct TreeNode* left;
        struct TreeNode* right;
};

int find_tree_height(struct TreeNode* root, int* max_length) {
    if (root == NULL) return 0;
    int left_height = find_tree_height(root->left, max_length);
    int right_height = find_tree_height(root->right, max_length);
    if (left_height + right_height > *max_length)
        *max_length = left_height + right_height;
    return (left_height > right_height ? left_height : right_height)+1;
}

int diameterOfBinaryTree(struct TreeNode* root) {
    int max_lenght = 0;
    find_tree_height(root, &max_lenght);
    return max_lenght;
}