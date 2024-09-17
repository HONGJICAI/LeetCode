// iteration.cpp
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
  vector<int> inorder;

public:
  vector<int> inorderTraversal(TreeNode *root) {
    stack<TreeNode *> st;
    while (1) {
      while (root != NULL) {
        st.push(root);
        root = root->left;
      }
      if (st.empty())
        break;
      root = st.top();
      st.pop();
      inorder.push_back(root->val);
      root = root->right;
    }
    return inorder;
  }
};
class SolutionDFS {
    void impl(vector<int>& res, TreeNode* node) {
        if (!node) return;
        if (node->left) {
            impl(res, node->left);
        }
        res.push_back(node->val);
        if (node->right) {
            impl(res, node->right);
        }
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        impl(res, root);
        return res;
    }
};