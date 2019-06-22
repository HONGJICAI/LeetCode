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
//Runtime: 120 ms, faster than 95.67% of C++ online submissions for Longest Univalue Path.
//Memory Usage: 49.7 MB, less than 64.70% of C++ online submissions for Longest Univalue Path.
public:
    int longestUnivaluePath(TreeNode* root) {
        int maxLen=0;
        function<int(TreeNode*,TreeNode*)>dfs=[&](TreeNode* root,TreeNode* parent){
            if(!root)
                return 0;
            int l=dfs(root->left,root);
            int r=dfs(root->right,root);
            maxLen=max(maxLen,l+r);
            return not parent or parent->val==root->val?max(l,r)+1:0;
        };
        dfs(root,nullptr);
        return maxLen;
    }
};