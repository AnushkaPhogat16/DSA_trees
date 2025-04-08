class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return nullptr;
        int cur = root->val;
        if(cur > p->val and cur > q->val) return lowestCommonAncestor(root->left, p, q);
        if(cur < p->val and cur < q->val) return lowestCommonAncestor(root->right, p, q);
        return root;
    }
};