// conciseIdea.cpp
class Solution {
public:
  int minDepth(TreeNode *root) {
    if (!root)
      return 0;
    if (!root->left)
      return 1 + minDepth(root->right);
    if (!root->right)
      return 1 + minDepth(root->left);
    return 1 + min(minDepth(root->left), minDepth(root->right));
  }
};
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
  int min = INT_MAX;

public:
  int minDepth(TreeNode *root) {
    if (!root)
      return 0;
    searchDepth(root, 1);
    return min;
  }
  void searchDepth(TreeNode *root, int depth) {
    if (root == NULL)
      return;
    if (!root->left && !root->right)
      min = min < depth ? min : depth;
    searchDepth(root->left, depth + 1);
    searchDepth(root->right, depth + 1);
  }
};
