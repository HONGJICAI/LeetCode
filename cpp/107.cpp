// dfsANDreverse.cpp
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
  vector<vector<int>> result;

public:
  vector<vector<int>> levelOrderBottom(TreeNode *root) {
    dfs(root, 0);
    return vector<vector<int>>(result.rbegin(), result.rend());
  }
  void dfs(TreeNode *root, int depth) {
    if (root == NULL)
      return;
    if (depth == result.size()) {
      result.push_back(vector<int>());
    }
    result[depth].push_back(root->val);
    dfs(root->left, depth + 1);
    dfs(root->right, depth + 1);
  }
};
