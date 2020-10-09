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
  void postOrderVisit(vector<int> &res, Node *root) {
    if (!root)
      return;
    for (auto &node : root->children) {
      postOrderVisit(res, node);
    }
    res.push_back(root->val);
  }

public:
  vector<int> postorder(Node *root) {
    vector<int> res;
    postOrderVisit(res, root);
    return res;
  }
};
