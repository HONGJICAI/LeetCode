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
    bool isBalance=1;
public:
    bool isBalanced(TreeNode* root) {
        getHeight(root);
        return isBalance;
    }
    int getHeight(TreeNode *root){
        if(!root){
            return 0;
        }
        int d1=getHeight(root->left)+1;
        int d2=getHeight(root->right)+1;
        if(abs(d1-d2)>=2)
            isBalance=0;
        return max(d1,d2);
    }
};
