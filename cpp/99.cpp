// inorder.cpp
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
  TreeNode *m1, *m2, *pre = NULL;
  bool firstOne = 1;

public:
  void recoverTree(TreeNode *root) {
    inorder(root);
    int temp = m1->val;
    m1->val = m2->val;
    m2->val = temp;
  }
  void inorder(TreeNode *root) {
    if (root == NULL)
      return;
    inorder(root->left);
    if (pre) {
      if (firstOne && root->val < pre->val) {
        m1 = pre;
        firstOne = 0;
      }
      if (!firstOne && root->val < pre->val) {
        m2 = root;
      }
    }
    pre = root;
    inorder(root->right);
  }
};
