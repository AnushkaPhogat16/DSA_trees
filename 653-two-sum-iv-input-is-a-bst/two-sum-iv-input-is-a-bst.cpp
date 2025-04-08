/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> seen;
        return inorder(root, seen, k);
    }

    bool inorder(TreeNode* root,unordered_set<int>& seen ,int k){
        if(!root) return false;

        if(seen.count(k - root->val)) return true;

        seen.insert(root->val);

        return inorder(root->left, seen, k) || inorder(root->right, seen, k);
    }
};