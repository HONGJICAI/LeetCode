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
    int sum=0;
public:
    int sumOfLeftLeaves(TreeNode* root) {
        getSum(root,0);
        return sum;
    }
    void getSum(TreeNode* root,bool isLeft){
        if(root==NULL)
            return;
        if(isLeft && root->left==NULL && root->right ==NULL)
            sum+=root->val;
        getSum(root->left,1);
        getSum(root->right,0);
    }
};
