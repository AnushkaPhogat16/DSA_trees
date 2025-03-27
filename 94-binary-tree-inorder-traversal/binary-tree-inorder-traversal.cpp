class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr = root;

        while (curr) {
            if (!curr->left) { 
                ans.push_back(curr->val);
                curr = curr->right; // Move to the right
            } else {
                TreeNode* pred = curr->left;
                while (pred->right && pred->right != curr) 
                    pred = pred->right; // Find predecessor
                
                if (!pred->right) { // First visit: Create thread
                    pred->right = curr;
                    curr = curr->left;
                } else { // Second visit: Break thread
                    pred->right = nullptr;
                    ans.push_back(curr->val); // Process node
                    curr = curr->right;
                }
            }
        }

        return ans;
    }
};
