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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return {};

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int levelSize = q.size();
            vector<int> currLevel;

            while(levelSize){
                TreeNode* curr = q.front();
                q.pop();
                currLevel.push_back(curr->val);
                levelSize--;

                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
                
            }

            ans.push_back(currLevel);
        }

        return ans;
    }
};