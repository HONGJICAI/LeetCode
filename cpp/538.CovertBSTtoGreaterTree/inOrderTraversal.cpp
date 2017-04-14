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
    TreeNode* convertBST(TreeNode* root) {
        inOrder(root);
        return root;
    }
    void inOrder(TreeNode* root){
        if(root==NULL)
            return;
        inOrder(root->right);
        int temp=root->val;
        root->val+=sum;
        sum+=temp;
        inOrder(root->left);
    }
};
