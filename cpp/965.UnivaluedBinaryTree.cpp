/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution { // Runtime: 0 ms, faster than 100.00% of C++ online submissions for Univalued Binary Tree.
public:
    bool isUnivalTree(TreeNode* root,TreeNode* parent=nullptr) {
        if(not root)
            return true;
        return (parent?root->val==parent->val:true) and isUnivalTree(root->left,root) and isUnivalTree(root->right,root);
    }
};