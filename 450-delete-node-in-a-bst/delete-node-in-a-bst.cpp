class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* parent = NULL;
        TreeNode* node = root;

        // Step 1: Find the node to delete
        while (node && node->val != key) {
            parent = node;
            if (key < node->val) node = node->left;
            else node = node->right;
        }

        if (!node) return root; // Key not found

        // Step 2: Handle deletion cases
        if (!node->left || !node->right) { // One or no child
            TreeNode* child = node->left ? node->left : node->right;
            if (!parent) return child; // If deleting root, return new root
            if (parent->left == node) parent->left = child;
            else parent->right = child;
            delete node;
        } 
        else { // Two children: Find inorder successor
            TreeNode* succParent = node;
            TreeNode* succ = node->right;
            while (succ->left) { // Find leftmost node in right subtree
                succParent = succ;
                succ = succ->left;
            }
            node->val = succ->val; // Copy successor value
            if (succParent->left == succ) succParent->left = succ->right;
            else succParent->right = succ->right;
            delete succ;
        }

        return root;
    }
};
