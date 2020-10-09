// usingStack.cpp
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
  stack<TreeNode *> st;

public:
  BSTIterator(TreeNode *root) {
    while (root != NULL) {
      st.push(root);
      root = root->left;
    }
  }

  /** @return whether we have a next smallest number */
  bool hasNext() { return !st.empty(); }

  /** @return the next smallest number */
  int next() {
    TreeNode *p = st.top();
    st.pop();
    int value = p->val;
    p = p->right;
    while (p != NULL) {
      st.push(p);
      p = p->left;
    }
    return value;
  }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
