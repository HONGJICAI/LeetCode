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
class Solution { // 136ms 99.81%
public:
    vector<vector<int>> levelOrder(Node* root) 
	{
        if (root == nullptr) 
			return {};
        vector<vector<int>> res;
        queue<Node*> q;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            vector<int> curLevel;
            while(size--)
            {
                auto tmp = q.front();
                q.pop();
                curLevel.push_back(tmp -> val);
                for (auto &n : tmp -> children)
                     q.push(n); 
            }
            res.push_back(curLevel);
        }
        return res; 
    }
};