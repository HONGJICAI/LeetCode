// queue.cpp
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
  vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
    queue<TreeNode *> qe;
    vector<vector<int>> result;
    if (root == NULL)
      return result;
    qe.push(root);
    TreeNode *p;
    int level = 0, size;
    while (!qe.empty()) {
      result.push_back(vector<int>(qe.size()));
      size = qe.size();
      for (int i = 0; i < size; ++i) {
        p = qe.front();
        qe.pop();
        result[level][i] = p->val;
        if (p->left != NULL)
          qe.push(p->left);
        if (p->right != NULL)
          qe.push(p->right);
      }
      if (qe.empty())
        break;
      ++level;
      result.push_back(vector<int>(qe.size()));
      for (int i = qe.size() - 1; i >= 0; --i) {
        p = qe.front();
        qe.pop();
        result[level][i] = p->val;
        if (p->left != NULL)
          qe.push(p->left);
        if (p->right != NULL)
          qe.push(p->right);
      }
      ++level;
    }
    return result;
  }
};
