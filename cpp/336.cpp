class Solution { // Time Limit Exceeded
public:
  vector<vector<int>> palindromePairs(vector<string> &words) {
    vector<vector<int>> ret;
    for (int i = 0; i < words.size(); ++i)
      for (int j = 0; j < words.size(); ++j)
        if (i == j)
          continue;
        else if (auto concat = words[i] + words[j];
                 concat == string(rbegin(concat), rend(concat)))
          ret.push_back({i, j});
    return ret;
  }
};
class Solution {
  // Runtime: 152 ms, faster than 94.79% of C++ online submissions for
  // Palindrome Pairs. Memory Usage: 28.2 MB, less than 94.95% of C++ online
  // submissions for Palindrome Pairs.
public:
  vector<vector<int>> palindromePairs(vector<string> &words) {
    auto palindrome = [](const string_view &s) {
      for (int i = 0, j = s.size() - 1; i < j;)
        if (s[i++] != s[j--])
          return false;
      return true;
    };
    unordered_map<string_view, int> hashmap;
    for (int i = 0; i < words.size(); ++i)
      hashmap[words[i]] = i;
    vector<vector<int>> ret;
    for (int i = 0; i < words.size(); ++i) {
      string_view s = words[i];
      auto cur = hashmap.find(s);
      for (int j = 0; j <= s.size(); ++j) {
        auto pre = s.substr(0, j);
        auto suf = s.substr(j);
        if (palindrome(suf)) {
          auto reverseStr = string(pre.rbegin(), pre.rend());
          if (auto it = hashmap.find(reverseStr);
              it != hashmap.end() && it != cur)
            ret.push_back({i, it->second});
        }
        if (palindrome(pre) && pre.size()) {
          auto reverseStr = string(suf.rbegin(), suf.rend());
          if (auto it = hashmap.find(reverseStr);
              it != hashmap.end() && it != cur)
            ret.push_back({it->second, i});
        }
      }
    }
    return ret;
  }
};