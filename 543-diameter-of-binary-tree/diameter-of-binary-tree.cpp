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
    int diameterOfBinaryTree(TreeNode* root) {

        int diameter = INT_MIN;

        maxH(root, diameter);

        return diameter;
    }

    int maxH(TreeNode* root, int& dia){
        if(!root) return 0;

        int lh = maxH(root->left, dia);
        int rh = maxH(root->right, dia);

        dia = max(dia, lh + rh);

        return 1 + max(lh , rh);


    }
};