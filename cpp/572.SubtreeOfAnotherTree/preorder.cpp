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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(s==NULL)return t==NULL;
        if(t==NULL)return false;
        bool res=0;
        if(s->val==t->val)
            res=isSame(s,t);
        return res||isSubtree(s->left,t)||isSubtree(s->right,t);
    }
    bool isSame(TreeNode* s, TreeNode* t){
        if(s==NULL)return t==NULL;
        if(t==NULL)return s==NULL;
        return s->val==t->val&&isSame(s->left,t->left)&&isSame(s->right,t->right);
    }
};
