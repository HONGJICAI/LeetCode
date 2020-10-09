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
class Solution { // Runtime: 136 ms, faster than 98.03% of C++ online
                 // submissions for Maximum Depth of N-ary Tree.
public:
  int maxDepth(Node *root) {
    if (not root)
      return 0;
    int depth = 0;
    for (auto &child : root->children)
      depth = max(depth, maxDepth(child));
    return 1 + depth;
  }
};