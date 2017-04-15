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
    int value;
public:
    int kthSmallest(TreeNode* root, int &k) {
        if(root==NULL)return 0;
        kthSmallest(root->left,k);
        if(k-->0)value=root->val;
        else return value;
        kthSmallest(root->right,k);
        return value;
    }
};
