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

    void inorderTrav(TreeNode* root ,vector<int>& ans){
        if(!root) return;

        //L root R

        inorderTrav(root->left, ans);
        ans.push_back(root->val);
        inorderTrav(root->right, ans);

    }
    bool isValidBST(TreeNode* root) {
        vector<int> ans;

        inorderTrav(root, ans);

        bool valid = true;

        for(int i = 1; i < ans.size(); i++){
            if(ans[i] <= ans[i-1]){
                valid = false;
                break;
            }
        }

        return valid;
    }
};