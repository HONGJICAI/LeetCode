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
    int maxDepth=-1;
    int value;
public:
    int findBottomLeftValue(TreeNode* root) {
        value=root->val;
        preorder(root,0);
        return value;
    }
    void preorder(TreeNode*root,int depth){
        if(root==NULL)return;
        if(depth>maxDepth){
            maxDepth=depth;
            value=root->val;
        }
        preorder(root->left,depth+1);
        preorder(root->right,depth+1);
    }
};
