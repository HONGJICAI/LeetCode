// hash.cpp
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
  unordered_map<int, int> map;
  int count = 0;

public:
  int pathSum(TreeNode *root, int sum) {
    map[0] = 1;
    preOrder(root, 0, sum);
    return count;
  }
  void preOrder(TreeNode *root, int cur, int sum) {
    if (root == NULL)
      return;
    cur += root->val;
    count += map[cur - sum];
    ++map[cur];
    preOrder(root->left, cur, sum);
    preOrder(root->right, cur, sum);
    --map[cur];
  }
};
