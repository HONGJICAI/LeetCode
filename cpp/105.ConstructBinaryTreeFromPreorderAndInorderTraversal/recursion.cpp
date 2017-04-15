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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()==0)return NULL;
        int k=0;
        return build(preorder,inorder,0,inorder.size()-1,k);
    }
    TreeNode* build(vector<int>& preorder, vector<int>& inorder,int i,int j,int &k) {
        for(;inorder[i]!=preorder[k]&&i<=j;++i);
        if(i>j||k>=preorder.size())return NULL;
        TreeNode *root=new TreeNode(preorder[k++]);
        root->left=build(preorder,inorder,0,i-1,k);
        root->right=build(preorder,inorder,i+1,j,k);
        return root;
    }
};
