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
//Runtime: 8 ms, faster than 92.53% of C++ online submissions for Maximum Difference Between Node and Ancestor.
public:
    int maxAncestorDiff(TreeNode* root) {
        int ret=0;
        function<void(TreeNode*,int,int)> recursion = [&ret,&recursion](auto root,auto maxVal,auto minVal){
            ret=max({abs(maxVal-root->val),abs(minVal-root->val),ret});
            maxVal=max(root->val,maxVal);
            minVal=min(root->val,minVal);
            if(root->left)
                recursion(root->left,maxVal,minVal);
            if(root->right)
                recursion(root->right,maxVal,minVal);
        };
        recursion(root,root->val,root->val);
        return ret;
    }
};