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
public:
  vector<int> preorderTraversal(TreeNode *root) {
    stack<TreeNode *> st;
    vector<int> result;
    while (1) {
      while (root != NULL) {
        result.push_back(root->val);
        st.push(root);
        root = root->left;
      }
      if (st.empty())
        break;
      root = st.top();
      st.pop();
      root = root->right;
    }
    while (!st.empty())
      ;
    return result;
  }
};
