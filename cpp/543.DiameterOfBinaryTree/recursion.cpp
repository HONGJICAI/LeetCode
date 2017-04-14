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
    int result=0;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        getDepth(root);
        return result;
    }
    int getDepth(TreeNode* root){
        if(root==NULL)
            return 0;
        int depth1=getDepth(root->left);
        int depth2=getDepth(root->right);
        if(depth1+depth2>result)
            result=depth1+depth2;
        return depth1>depth2?depth1+1:depth2+1;
    }
};
