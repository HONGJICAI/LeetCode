// recursion.cpp
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
    int maxSum = INT_MIN;
    int maxPath(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int left = maxPath(root->left), right = maxPath(root->right);
        maxSum = max(maxSum, root->val + (left > 0 ? left : 0) +
                                 (right > 0 ? right : 0));
        int sub = max(left, right);
        return max(sub + root->val, root->val);
    }

  public:
    int maxPathSum(TreeNode* root) {
        maxPath(root);
        return maxSum;
    }
};
