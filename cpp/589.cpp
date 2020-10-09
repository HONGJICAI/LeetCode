// recursion.cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
  void preOrderVisit(vector<int> &res, Node *root) {
    if (!root)
      return;
    res.push_back(root->val);
    for (auto &node : root->children)
      preOrderVisit(res, node);
  }

public:
  vector<int> preorder(Node *root) {
    vector<int> res;
    preOrderVisit(res, root);
    return res;
  }
};
