// iteration.cpp
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
  void connect(TreeLinkNode *root) {
    while (root && root->left) {
      TreeLinkNode *p = root;
      while (root) {
        root->left->next = root->right;
        if (!root->next)
          break;
        root->right->next = root->next->left;
        root = root->next;
      }
      root = p->left;
    }
  }
};
