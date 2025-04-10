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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int> > > mp; //vertical, level, values into multiset
        queue< pair<TreeNode* , pair<int , int> > > q; //node, vertical, level

        q.push({root, {0, 0}});

        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            TreeNode* node = curr.first;
            int vertical = curr.second.first;
            int level = curr.second.second;

            mp[vertical][level].insert(node->val);

            if(node -> left){
                q.push({node->left, {vertical - 1, level + 1}} );
            }

            if(node->right){
                q.push({node->right, {vertical + 1, level + 1}} );
            }
        }

        vector<vector<int>> ans;

        for(auto curr : mp){
            vector<int> col;
            for(auto q : curr.second){
                col.insert(col.end(), q.second.begin(), q.second.end());
            }

            ans.push_back(col);
        }

        return ans;
    }
};