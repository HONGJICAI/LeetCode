// recursion-6ms.cpp
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
  int maxDepth(TreeNode *root) {
    if (root == NULL)
      return 0;
    int a = 1 + maxDepth(root->left), b = 1 + maxDepth(root->right);
    if (a >= b)
      return a;
    return b;
  }
};
