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
  // Runtime: 32 ms, faster than 87.87% of C++ online submissions for Delete
  // Node in a BST. Memory Usage: 12.8 MB, less than 69.11% of C++ online
  // submissions for Delete Node in a BST.
public:
  TreeNode *deleteNode(TreeNode *root, int key) {
    if (not root)
      return root;
    if (root->val > key) {
      root->left = deleteNode(root->left, key);
      return root;
    }
    if (root->val < key) {
      root->right = deleteNode(root->right, key);
      return root;
    }
    static auto leftTreeRightMost = [](auto root) {
      auto node = root->left;
      while (node && node->right)
        node = node->right;
      return node;
    };
    static auto rightTreeLeftMost = [](auto root) {
      auto node = root->right;
      while (node && node->left)
        node = node->left;
      return node;
    };
    if (auto l = leftTreeRightMost(root); l) {
      root->val = l->val;
      root->left = deleteNode(root->left, l->val);
      return root;
    }
    if (auto r = rightTreeLeftMost(root); r) {
      root->val = r->val;
      root->right = deleteNode(root->right, r->val);
      return root;
    }
    return nullptr;
  }
};