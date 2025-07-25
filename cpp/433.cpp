class Solution {
    bool oneDiffer(string_view a, string_view b) {
        int cnt = 0;
        for (int i = 0; i < 8; ++i) {
            if (a[i] != b[i]) {
                ++cnt;
                if (cnt > 1)
                    return false;
            }
        }
        return cnt == 1;
    }
    int bfs(string_view startGene, string_view endGene,
            unordered_map<string_view, unordered_set<string_view>>& graph) {
        deque<string_view> q = {startGene};
        unordered_set<string_view> visited;
        auto ret = 0;
        while (q.size() > 0) {
            int batchCnt = q.size();
            for (int i = 0; i < batchCnt; ++i) {
                auto cur = q.front();
                q.pop_front();
                visited.insert(cur);
                for (auto& next : graph[cur]) {
                    if (next == endGene)
                        return ret + 1;
                    else if (!visited.contains(next))
                        q.push_back(next);
                }
            }
            ++ret;
        }
        return -1;
    }

public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        if (startGene == endGene)
            return 0;
        unordered_map<string_view, unordered_set<string_view>> graph = {
            {startGene, {}}};
        for (auto& gene : bank)
            graph[gene] = {};
        if (!graph.contains(endGene))
            return -1;
        for (auto it1 = graph.begin(); it1 != graph.end(); ++it1) {
            auto it2 = it1;
            for (++it2; it2 != graph.end(); ++it2) {
                if (oneDiffer(it1->first, it2->first)) {
                    it1->second.insert(it2->first);
                    it2->second.insert(it1->first);
                }
            }
        }
        return bfs(startGene, endGene, graph);
    }
};