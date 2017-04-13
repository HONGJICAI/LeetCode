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
    int min;
    int lastValue;
public:
    int getMinimumDifference(TreeNode* root) {
        min=INT_MAX;
        lastValue=-1;
        getMinimum(root);
        return min;
    }
    void getMinimum(TreeNode* root){
        if(root->left!=NULL)
            getMinimum(root->left);
        if( lastValue>=0 && abs(lastValue-root->val)<min )
            min=abs(lastValue-root->val);
        lastValue=root->val;
        if(root->right!=NULL)
            getMinimum(root->right);
    }
};
