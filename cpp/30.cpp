class Solution { // 10ms Beats 97.71%  
public:
    vector<int> findSubstring(string s, vector<string>& L) {
        vector<int> ans;
        if (s.size() == 0 || L.size() == 0)
            return ans;
        string_view sv = s;
        unordered_map<string_view, int> dict;
        for (const auto& s : L)
            ++dict[s];
        const int wl = L[0].size(), totalLength = L.size() * wl;
        auto moveLWin = [wl](auto& tdict, auto& sv, auto& left, auto& count) {
            --tdict[sv.substr(left, wl)];
            --count;
            left += wl;
        };
        for (int i = 0; i < wl; ++i) {
            int left = i, count = 0;
            unordered_map<string_view, int> tdict;
            for (int j = i; left + totalLength <= sv.size(); j += wl)
                if (auto str = sv.substr(j, wl); dict.contains(str)) {
                    ++tdict[str];
                    ++count;
                    if (count == L.size() && tdict[str] == dict[str]) {
                        ans.push_back(left);
                        moveLWin(tdict, sv, left, count);
                    } else
                        while (tdict[str] > dict[str])
                            moveLWin(tdict, sv, left, count);
                } else {
                    tdict.clear();
                    count = 0;
                    left = j + wl;
                }
        }
        return ans;
    }
};