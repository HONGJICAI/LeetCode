// recursion.cpp
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
  int maxSum = INT_MIN;

public:
  int maxPathSum(TreeNode *root) {
    maxPath(root);
    return maxSum;
  }
  int maxPath(TreeNode *root) {
    if (root == NULL)
      return 0;
    int left = maxPath(root->left), right = maxPath(root->right);
    maxSum = max(maxSum,
                 root->val + (left > 0 ? left : 0) + (right > 0 ? right : 0));
    int sub = max(left, right);
    return max(sub + root->val, root->val);
  }
};
