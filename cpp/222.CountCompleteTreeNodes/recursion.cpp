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
    int countNodes(TreeNode* root) {
        if(!root)
            return 0;
        TreeNode *l=root,*r=root;
        int ld=0,rd=0;
        while(l){
            ++ld;
            l=l->left;
        }
        while(r){
            ++rd;
            r=r->right;
        }
        if(ld==rd)
            return (1<<ld)-1;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};
