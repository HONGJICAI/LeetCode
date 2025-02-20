// recursion-9ms.cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
class Solution {
  public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == nullptr)
            return 0;
        if (root->val == sum && root->left == nullptr && root->right == nullptr)
            return 1;
        return hasPathSum(root->left, sum - root->val) ||
               hasPathSum(root->right, sum - root->val);
    }
};
