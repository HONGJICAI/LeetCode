// dfs.cpp
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
  int v, d;
  void dfs(TreeNode *root, int level) {
    if (root == nullptr)
      return;
    if (level == d) {
      TreeNode *node = new TreeNode(v);
      node->left = root->left;
      root->left = node;
      node = new TreeNode(v);
      node->right = root->right;
      root->right = node;
      return;
    }
    dfs(root->left, level + 1);
    dfs(root->right, level + 1);
  }

public:
  TreeNode *addOneRow(TreeNode *root, int v, int d) {
    this->v = v;
    this->d = d;
    if (d == 1) {
      TreeNode *node = new TreeNode(v);
      node->left = root;
      return node;
    }
    dfs(root, 2);
    return root;
  }
};
