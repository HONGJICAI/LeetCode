// preorder.cpp
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
  void preorder(vector<int> &nums, TreeNode *root, int depth) {
    if (!root)
      return;
    if (nums.size() == depth)
      nums.push_back(root->val);
    preorder(nums, root->right, depth + 1);
    preorder(nums, root->left, depth + 1);
  }
public:
  vector<int> rightSideView(TreeNode *root) {
    vector<int> result;
    preorder(result, root, 0);
    return result;
  }
};
