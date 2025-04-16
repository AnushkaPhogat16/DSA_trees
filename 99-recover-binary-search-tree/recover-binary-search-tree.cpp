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
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> inorderNodes;
        inorderTrav(root, inorderNodes);

        TreeNode* first = nullptr;
        TreeNode* second = nullptr;

        // Find the two nodes that are out of order
        for (int i = 0; i < inorderNodes.size() - 1; ++i) {
            if (inorderNodes[i]->val > inorderNodes[i + 1]->val) {
                if (!first) {
                    first = inorderNodes[i];
                }
                second = inorderNodes[i + 1];
            }
        }

        // Swap the values of the two nodes
        if (first && second) {
            swap(first->val, second->val);
        }
    }

    void inorderTrav(TreeNode* root, vector<TreeNode*>& inorderVec) {
        if (!root) return;

        inorderTrav(root->left, inorderVec);
        inorderVec.push_back(root);
        inorderTrav(root->right, inorderVec);
    }
};
