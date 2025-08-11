/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int globalMax;

// Utility function: max of two ints
int max(int a, int b) {
    return (a > b) ? a : b;
}

// DFS function to compute max gain
int maxGain(struct TreeNode* node) {
    if (!node) return 0;

    // Compute gains from left and right subtrees
    int leftGain = max(maxGain(node->left), 0);
    int rightGain = max(maxGain(node->right), 0);

    // Path passing through this node
    int currentPathSum = node->val + leftGain + rightGain;

    // Update global maximum if needed
    if (currentPathSum > globalMax)
        globalMax = currentPathSum;

    // Return max gain to parent (only one side can be chosen)
    return node->val + max(leftGain, rightGain);
}

int maxPathSum(struct TreeNode* root) {
    globalMax = INT_MIN; // Initialize to very small
    maxGain(root);
    return globalMax;
}
