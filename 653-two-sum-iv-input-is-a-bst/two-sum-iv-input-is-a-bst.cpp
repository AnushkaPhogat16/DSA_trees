class Solution {
public:
    TreeNode* search(TreeNode* root, int target, TreeNode* avoid) {
        while (root) {
            if (root->val == target && root != avoid) return root;
            root = (target < root->val) ? root->left : root->right;
        }
        return nullptr;
    }

    bool findPair(TreeNode* root, TreeNode* node, int k) {
        if (!node) return false;
        if (search(root, k - node->val, node)) return true;
        return findPair(root, node->left, k) || findPair(root, node->right, k);
    }

    bool findTarget(TreeNode* root, int k) {
        return findPair(root, root, k);
    }
};
