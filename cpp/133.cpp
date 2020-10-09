/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
  // Runtime: 24 ms, faster than 92.17% of C++ online submissions for Clone
  // Graph. Memory Usage: 16.8 MB, less than 12.63% of C++ online submissions
  // for Clone Graph.

public:
  Node *cloneGraph(Node *node) {
    unordered_map<Node *, Node *> copies;
    function<Node *(Node *)> dfs = [&copies, &dfs](Node *node) -> Node * {
      if (!node)
        return nullptr;
      if (copies.find(node) == copies.end()) {
        copies[node] = new Node(node->val, {});
        for (Node *neighbor : node->neighbors) {
          copies[node]->neighbors.push_back(dfs(neighbor));
        }
      }
      return copies[node];
    };
    return dfs(node);
  }
};