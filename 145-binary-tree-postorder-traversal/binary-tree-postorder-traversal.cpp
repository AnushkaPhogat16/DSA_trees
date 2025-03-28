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
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root) return {};
        vector<int> ans;
        stack<TreeNode* > st;

        TreeNode* curr = root;
        TreeNode* lastVisited = nullptr;

        while(!st.empty() || curr){
            if(curr){
                st.push(curr);
                curr = curr->left;
            }else{
                TreeNode* top = st.top();

                if(top->right && lastVisited != top->right){
                    curr= top->right;
                }else{
                    ans.push_back(top->val);
                    lastVisited = top;
                    st.pop();
                }
            }
        }


        return ans;


    }
};