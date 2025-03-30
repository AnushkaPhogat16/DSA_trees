class Solution {
public:
    int solve(TreeNode* root, int &maxSum) {
        if (!root) return 0;

        int lSum = max(0, solve(root->left, maxSum));  // Ignore negative paths
        int rSum = max(0, solve(root->right, maxSum));

        int currMax = root->val + lSum + rSum; // Max path including current root

        maxSum = max(maxSum, currMax); // Update global max path sum

        return root->val + max(lSum, rSum); // Return max path sum extending downward
    }

    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        solve(root, maxSum);
        return maxSum;
    }
};
