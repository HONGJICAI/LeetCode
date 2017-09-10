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
    int minValue;
    int *sec_min;
public:
    int findSecondMinimumValue(TreeNode* root) {
        if(!root)
            return -1;
        minValue=root->val;
        sec_min=nullptr;
        helper(root->left);
        helper(root->right);
        return sec_min==nullptr?-1:*sec_min;
    }
    void helper(TreeNode* root){
        if(!root)
            return;
        if(root->val > minValue)
            sec_min= sec_min==nullptr? &root->val : *sec_min >root->val ? &root->val : sec_min ;
        helper(root->left);
        helper(root->right);
    }
};
