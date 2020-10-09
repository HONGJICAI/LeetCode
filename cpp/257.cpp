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
  vector<string> binaryTreePaths(TreeNode *root) {
    vector<string> result;
    if (root == NULL)
      return result;
    if (root->left == NULL && root->right == NULL) {
      result.push_back(to_string(root->val));
      return result;
    }
    preOrder(result, root->left, to_string(root->val));
    preOrder(result, root->right, to_string(root->val));
    return result;
  }
  void preOrder(vector<string> &result, TreeNode *root, string str) {
    if (root == NULL)
      return;
    str += "->" + to_string(root->val);
    if (root->left == NULL && root->right == NULL)
      result.push_back(str);
    preOrder(result, root->left, str);
    preOrder(result, root->right, str);
  }
};