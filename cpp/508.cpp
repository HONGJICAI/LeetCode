// hash_postorder.cpp
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
  vector<int> result;

public:
  vector<int> findFrequentTreeSum(TreeNode *root) {
    if (root == NULL)
      return result;
    postorder(root);
    int max = 0, f;
    for (auto it = map.begin(); it != map.end(); ++it)
      if (it->second > max) {
        max = it->second;
        result.assign(1, it->first);
      } else if (it->second == max)
        result.push_back(it->first);
    return result;
  }
  int postorder(TreeNode *root) {
    int left = 0, right = 0;
    if (root->left)
      left = postorder(root->left);
    if (root->right)
      right = postorder(root->right);
    map[root->val + left + right]++;
    return root->val + left + right;
  }
};
