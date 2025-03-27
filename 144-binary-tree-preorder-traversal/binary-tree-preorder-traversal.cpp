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
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode* curr = root;

        while(curr){
            //CASE1: No leftchild
            //Visit node, move right
            if(!curr->left){
                res.push_back(curr->val);
                curr = curr->right;
            }else{
                //find predecessor
                //(rightmost node in left subtree)
                TreeNode* pred = curr->left;
                while(pred-> right && pred-> right != curr){
                    pred = pred->right;
                }

                //create thread (first visit)
                if(!pred->right){
                    pred->right = curr; //threading
                    res.push_back(curr->val);
                    curr = curr->left;
                }else{
                    //break thread(second visit)
                    pred->right = nullptr; //remove thread
                    curr = curr->right;
                }
            }
        }

        return res;


        

    }



    
};