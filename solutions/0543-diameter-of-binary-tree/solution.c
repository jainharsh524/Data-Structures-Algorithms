int globalDiameter;

int max(int a, int b) {
    return (a > b) ? a : b;
}

int depth(struct TreeNode* node) {
    if (!node) return 0;
    int left = depth(node->left);
    int right = depth(node->right);
    // Path through this node
    if (left + right > globalDiameter)
        globalDiameter = left + right;
    return 1 + max(left, right);
}

int diameterOfBinaryTree(struct TreeNode* root) {
    globalDiameter = 0;
    depth(root);
    return globalDiameter;
}
