class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> qu;
        qu.push(p);
        qu.push(q);

        while (!qu.empty()) {
            TreeNode* node1 = qu.front(); qu.pop();
            TreeNode* node2 = qu.front(); qu.pop();

            if (!node1 && !node2) continue;
            if (!node1 || !node2 || node1->val != node2->val) return false;

            qu.push(node1->left);
            qu.push(node2->left);
            qu.push(node1->right);
            qu.push(node2->right);
        }
        return true;
    }
};
