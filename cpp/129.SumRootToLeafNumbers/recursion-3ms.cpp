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
public:
    int sumNumbers(TreeNode* root) {
        int sum=0;
        calc(root,0,sum);
        return sum;
    }
    void calc(TreeNode *root,int value,int &sum){
        if(root==NULL)
            return;
        value=value*10+root->val;
        if(root->left==NULL && root->right==NULL){
            sum+=value;
            return;
        }
        calc(root->left,value,sum);
        calc(root->right,value,sum);
            
    }
};