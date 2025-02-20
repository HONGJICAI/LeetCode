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
  TreeLinkNode *getFirstChild(TreeLinkNode *&root) {
    for (; root; root = root->next) {
      if (root->left)
        return root->left;
      if (root->right)
        return root->right;
    }
    return nullptr;
  }
  TreeLinkNode *getNext(TreeLinkNode *now, TreeLinkNode *&parent) {
    if (parent->left == now && parent->right)
      return parent->right;
    for (parent = parent->next; parent; parent = parent->next) {
      if (parent->left)
        return parent->left;
      if (parent->right)
        return parent->right;
    }
    return nullptr;
  }

public:
  void connect(TreeLinkNode *root) {
    while (root) {
      TreeLinkNode *head = getFirstChild(root);
      for (TreeLinkNode *cur = head; cur; cur = cur->next)
        cur->next = getNext(cur, root);
      root = head;
    }
  }
};
