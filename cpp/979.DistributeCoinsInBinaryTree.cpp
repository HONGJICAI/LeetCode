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
//Runtime: 8 ms, faster than 88.79% of C++ online submissions for Distribute Coins in Binary Tree.
//Memory Usage: 13.2 MB, less than 59.61% of C++ online submissions for Distribute Coins in Binary Tree.
public:
    int distributeCoins(TreeNode* root) {
        int ret=0;
        function<int(TreeNode*)> recursion= [&ret,&recursion](TreeNode*root){
            if(!root)
                return 0;
            auto leftNeed=recursion(root->left);
            auto rightNeed=recursion(root->right);
            ret+=abs(leftNeed)+abs(rightNeed);
            root->val-=leftNeed+rightNeed;
            return 1-root->val;
        };
        recursion(root);
        return ret;
    }
};