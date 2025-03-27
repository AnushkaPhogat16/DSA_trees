class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* curr = root;

        while (curr || !st.empty()) {
            while (curr) { // Go left as much as possible
                st.push(curr);
                curr = curr->left;
            }
            
            curr = st.top(); // Process node
            st.pop();
            ans.push_back(curr->val);

            curr = curr->right; // Move to right child
        }
        
        return ans;
    }
};
