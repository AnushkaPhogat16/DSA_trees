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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};  // Handle empty tree case

        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> ans;
        bool leftToRight = true; // Track order of traversal

        while (!q.empty()) {
            int size = q.size();
            vector<int> level(size);

            for (int i = 0; i < size; i++) {
                TreeNode* temp = q.front();
                q.pop();

                // Place element in correct index based on zigzag pattern
                int index = leftToRight ? i : (size - 1 - i);
                level[index] = temp->val;

                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }

            ans.push_back(level);
            leftToRight = !leftToRight;  // Toggle direction after processing each level
        }

        return ans;
    }
};