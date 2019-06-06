/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
//Runtime: 4 ms, faster than 93.18% of C++ online submissions for Flip Equivalent Binary Trees.
//Memory Usage: 11.8 MB, less than 53.59% of C++ online submissions for Flip Equivalent Binary Trees.
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if ((!root1 && root2) || (root1 && !root2))         
            return false;
        return (!root1)||((root1->val ==root2->val) && (
                         (flipEquiv (root1->right, root2->left) && flipEquiv (root1->left, root2->right) )  ||
                         (flipEquiv (root1->left, root2->left) && flipEquiv (root1->right, root2->right) )  )); 
    }
};