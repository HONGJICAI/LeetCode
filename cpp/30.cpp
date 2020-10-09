class Solution {
  // Runtime: 20 ms, faster than 98.91% of C++ online submissions for Substring
  // with Concatenation of All Words. Memory Usage: 10.8 MB, less than 99.11% of
  // C++ online submissions for Substring with Concatenation of All Words.
public:
  vector<int> findSubstring(string SS, vector<string> &L) {
    vector<int> ans;
    if (SS.size() == 0 || L.size() == 0)
      return ans;
    string_view S = SS;
    unordered_map<string_view, int> dict;
    for (const auto &s : L)
      ++dict[s];
    const int wl = L[0].size();
    const int totalLength = L.size() * wl;
    auto slideLeftWindow = [wl](auto &tdict, auto &S, auto &left, auto &count) {
      --tdict[S.substr(left, wl)];
      --count;
      left += wl;
    };
    for (int i = 0; i < wl; ++i) {
      int left = i, count = 0;
      unordered_map<string_view, int> tdict;
      for (int j = i; left + totalLength <= S.size(); j += wl)
        if (auto str = S.substr(j, wl); dict.count(str)) {
          ++tdict[str];
          ++count;
          if (tdict[str] <= dict[str] && count == L.size()) {
            ans.push_back(left);
            slideLeftWindow(tdict, S, left, count);
          } else
            while (tdict[str] > dict[str])
              slideLeftWindow(tdict, S, left, count);
        } else {
          tdict.clear();
          count = 0;
          left = j + wl;
        }
    }
    return ans;
  }
};