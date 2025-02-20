/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution { // Runtime: 0 ms, faster than 100.00% of C++ online submissions
                 // for Binary Search Tree to Greater Sum Tree.
public:
  TreeNode *bstToGst(TreeNode *root, int pre = 0) {
    function<void(TreeNode * root)> reverse = [&pre, &reverse](TreeNode *node) {
      if (node->right)
        reverse(node->right);
      pre = node->val = pre + node->val;
      if (node->left)
        reverse(node->left);
    };
    reverse(root);
    return root;
  }
};