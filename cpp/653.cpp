// hashset.cpp
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
  unordered_set<int> hashset;

public:
  bool findTarget(TreeNode *root, int k) {
    if (!root)
      return false;
    if (hashset.find(k - root->val) != hashset.end())
      return true;
    hashset.insert(root->val);
    return findTarget(root->left, k) || findTarget(root->right, k);
  }
};
