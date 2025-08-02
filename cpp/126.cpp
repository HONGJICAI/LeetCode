class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string_view> hash(wordList.begin(), wordList.end());
        if (!hash.contains(endWord)) return {};
        vector<vector<string>> ret;
        deque<string_view> dq = {beginWord};
        unordered_map<string_view, int> string2dist = { {beginWord, 0} };
        unordered_map<string_view, list<string_view>> preNodes;
        bool found = false;
        int level = 0;
        while (dq.size() > 0 && !found) {
            int size = dq.size();
            unordered_set<string_view> visitedNow;
            for (int i = 0; i < size; ++i) {
                auto word = dq.front();
                dq.pop_front();
                string s = {word.begin(), word.end()};
                for (int i = 0; i < s.size(); ++i) {
                    for (char ch = 'a'; ch <= 'z'; ++ch) {
                        if (ch == word[i]) continue;
                        s[i] = ch;
                        if (auto it = hash.find(s); it != hash.end()) {
                            if (!string2dist.contains(*it)){
                                if (s == endWord) {
                                    found = true;
                                }
                                preNodes[*it].push_back(word);
                                visitedNow.insert(*it);
                            }
                        }
                    }
                    s[i] = word[i];
                }
            }
            for (auto& sv: visitedNow) {
                dq.push_back(sv);
                string2dist[sv] = level + 1;
            }
            ++level;
        }
        if (found) {
            int l = level - 1;
            vector<string> path = { };
            function<void(string&)> dfs = [&](auto& cur) {
                path.push_back(cur);
                if (l == -1) {
                    ret.push_back({path.rbegin(), path.rend()});
                    path.pop_back();
                    return;
                }
                for (auto& s: preNodes[cur]) {
                    if (string2dist[s] == l) {
                        auto str = string(s);
                        --l;
                        dfs(str);
                        ++l;
                    }
                }
                path.pop_back();
            };
            dfs(endWord);
        }
        return ret;
    }
};