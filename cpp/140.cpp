class Solution {
  public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        string_view sv = s;
        unordered_set<string_view> hashset(wordDict.begin(), wordDict.end());
        vector<int> dp(s.size() + 1, 0);
        vector<vector<string>> ret(s.size() + 1);
        dp[0] = 1;
        for (int i = 1; i <= s.size(); ++i)
            for (int j = i - 1; j >= 0; --j)
                if (dp[j] &&
                    hashset.find(sv.substr(j, i - j)) != hashset.end()) {
                    dp[i] = true;
                    if (ret[j].empty())
                        ret[i].push_back(string(sv.substr(j, i - j)));
                    else
                        for (auto& str : ret[j])
                            ret[i].push_back(str + " " +
                                             string(sv.substr(j, i - j)));
                }
        return ret.back();
    }
};