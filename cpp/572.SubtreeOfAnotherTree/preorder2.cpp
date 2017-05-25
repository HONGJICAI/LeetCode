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
        string ss,tt;
        preorder(s,ss);
        preorder(t,tt);
        return ss.find(tt)!=std::string::npos;
    }
    void preorder(TreeNode *root,string &s){
            s+=",";
        if(root==NULL){
            s+="#";
            return;
        }
        s+=to_string(root->val);
        preorder(root->left,s);
        preorder(root->right,s);
    }
};
