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
    vector<vector<string>> printTree(TreeNode* root) {
        int m=getHeight(root);
        if(m==0)return vector<vector<string>>(1,vector<string>(1,""));
        int n=(1<<m)-1;
        vector<vector<string>>res(m,vector<string>(n,""));
        fillVector(res,root,0,n-1,0);
        return res;
    }
    void fillVector(vector<vector<string>>&res,TreeNode* root,int l,int r,int h){
        if(!root)
            return;
        int mid=(l+r)/2;
        res[h][mid]=to_string(root->val);
        fillVector(res,root->left,l,mid-1,h+1);
        fillVector(res,root->right,mid+1,r,h+1);
    }
    int getHeight(TreeNode* root){
        if(root==nullptr)
            return 0;
        int l=getHeight(root->left);
        int r=getHeight(root->right);
        return l>r?l+1:r+1;
    }
};
