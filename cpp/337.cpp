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
  // Runtime: 16 ms, faster than 91.42% of C++ online submissions for House
  // Robber III. Memory Usage: 20.3 MB, less than 99.84% of C++ online
  // submissions for House Robber III.
public:
  int rob(TreeNode *root) {
    function<pair<int, int>(TreeNode *)> recursion =
        [&recursion](TreeNode *root) -> pair<int, int> {
      if (not root)
        return {0, 0};
      auto [takel, notakel] = recursion(root->left);
      auto [taker, notaker] = recursion(root->right);
      return {max(root->val, 0) + notakel + notaker,
              max(takel, notakel) + max(taker, notaker)};
    };
    const auto [a, b] = recursion(root);
    return max(a, b);
  }
};