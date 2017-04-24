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
    int findTilt(TreeNode* root) {
        postorder(root);
        return sum;
    }
    int postorder(TreeNode* root) {
        if(root==NULL)return 0;
        int left=postorder(root->left);
        int right=postorder(root->right);
        int tilt=abs(left-right);
        sum+=tilt;
        return left+right+root->val;
    }
};
