// TLE - DFS with memoization
// Failed at case n = 20000
using IntPair = pair<int, int>;
template <> struct std::hash<IntPair> {
    std::size_t operator()(const IntPair& k) const {
        return std::hash<int>()(k.first) ^ std::hash<int>()(k.second);
    }
};
class Solution {
    int dfs(unordered_map<int, unordered_set<int>>& graph,
            unordered_map<IntPair, int>& cacheHeights, int root, int parent) {
        if (auto it = cacheHeights.find({parent, root});
            it != cacheHeights.end())
            return it->second;
        int height = 1;
        for (auto& child : graph[root]) {
            if (child == parent)
                continue;
            height = max(1 + dfs(graph, cacheHeights, child, root), height);
        }
        cacheHeights[{parent, root}] = height;
        return height;
    }

public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        unordered_map<int, unordered_set<int>> graph;
        for (auto& edge : edges) {
            graph[edge[0]].insert(edge[1]);
            graph[edge[1]].insert(edge[0]);
        }
        unordered_map<IntPair, int> cacheHeights;
        int minHeight = INT_MAX;
        vector<int> ret;
        for (int i = 0; i < n; ++i) {
            auto height = dfs(graph, cacheHeights, i, -1);
            if (height < minHeight) {
                ret = {i};
                minHeight = height;
            } else if (height == minHeight) {
                ret.push_back(i);
            }
        }
        return ret;
    }
};

class Solution2 {
    vector<int> maxPath(unordered_map<int, unordered_set<int>>& graph,
                        int root) {
        vector<int> ret;
        vector<int> path;
        function<void(int, int, vector<int>&)> dfs = [&](int root, int parent,
                                                         vector<int>& path) {
            path.push_back(root);
            if (graph[root].size() == 1 && graph[root].count(parent)) {
                if (path.size() > ret.size()) {
                    ret = path;
                }
                path.pop_back();
                return;
            }
            for (auto& child : graph[root]) {
                if (child == parent)
                    continue;
                dfs(child, root, path);
            }
            path.pop_back();
        };
        dfs(root, -1, path);
        return ret;
    }

public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        unordered_map<int, unordered_set<int>> graph;
        for (auto& edge : edges) {
            graph[edge[0]].insert(edge[1]);
            graph[edge[1]].insert(edge[0]);
        }
        auto path = maxPath(graph, 0);
        if (path.size() == 0) {
            return {0};
        }
        path = maxPath(graph, path.back());
        if (path.size() % 2 == 0) {
            return {path[path.size() / 2 - 1], path[path.size() / 2]};
        } else {
            return {path[path.size() / 2]};
        }
    }
};