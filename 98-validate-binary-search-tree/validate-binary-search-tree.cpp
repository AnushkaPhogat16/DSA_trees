class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return inorderCheck(root, nullptr, nullptr);
    }

private:
    bool inorderCheck(TreeNode* root, TreeNode* minNode, TreeNode* maxNode) {
        if (!root) return true;

        if ((minNode && root->val <= minNode->val) || 
            (maxNode && root->val >= maxNode->val)) {
            return false;
        }

        return inorderCheck(root->left, minNode, root) && inorderCheck(root->right, root, maxNode);
    }
};
