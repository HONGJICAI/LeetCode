/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
  public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> copies;
        function<Node*(Node*)> dfs = [&copies, &dfs](Node* node) -> Node* {
            if (!node)
                return nullptr;
            if (auto it = copies.find(node); it != copies.end()) {
                return it->second;
            }
            auto p = copies[node] = new Node(node->val, {});
            for (auto neighbor : node->neighbors) {
                p->neighbors.push_back(dfs(neighbor));
            }
            return p;
        };
        return dfs(node);
    }
};