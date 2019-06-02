/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution { //Runtime: 92 ms, faster than 84.56% of C++ online submissions for Insert into a Binary Search Tree.
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root)
            return new TreeNode(val);
        auto &target=root->val>val?root->left:root->right;
        if(!target)
            target=new TreeNode(val);
        else
            insertIntoBST(target,val);
        return root;
    }
};