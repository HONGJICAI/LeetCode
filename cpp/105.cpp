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
  // Runtime: 20 ms, faster than 79.16% of C++ online submissions for Construct
  // Binary Tree from Preorder and Inorder Traversal. Memory Usage: 19.2 MB,
  // less than 25.65% of C++ online submissions for Construct Binary Tree from
  // Preorder and Inorder Traversal.
public:
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    if (!preorder.size())
      return nullptr;
    using itr = vector<int>::iterator;
    function<TreeNode *(itr, itr, itr &)> build =
        [&build](itr first, itr last, itr &t) -> TreeNode * {
      auto it = find(first, last, *t);
      if (it == last)
        return nullptr;
      TreeNode *root = new TreeNode(*t++);
      root->left = build(first, it, t);
      root->right = build(it + 1, last, t);
      return root;
    };
    auto it = begin(preorder);
    return build(begin(inorder), end(inorder), it);
  }
};