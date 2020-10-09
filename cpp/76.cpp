// hashmap.cpp
class Solution {
  bool allContain(unordered_map<char, int> &hash) {
    for (auto p : hash)
      if (p.second > 0)
        return 0;
    return 1;
  }

public:
  string minWindow(string s, string t) {
    int l = 0, r = 0, minLen = 0x7fffffff, start;
    unordered_map<char, int> hash;
    for (char ch : t)
      hash[ch]++;
    unordered_map<char, int>::iterator it;
    while (r < s.size() || allContain(hash)) {
      while (r < s.size() && !allContain(hash))
        if ((it = hash.find(s[r++])) != hash.end())
          it->second--;
      while (l < r && allContain(hash)) {
        if (r - l < minLen) {
          minLen = r - l;
          start = l;
        }
        if ((it = hash.find(s[l++])) != hash.end())
          it->second++;
      }
    }
    return minLen == 0x7fffffff ? "" : s.substr(start, minLen);
  }
};
// simple.cpp
class Solution {
  bool allContain(vector<int> &arr) {
    for (auto num : arr)
      if (num > 0)
        return 0;
    return 1;
  }

public:
  string minWindow(string s, string t) {
    int l = 0, r = 0, minLen = 0x7fffffff, start;
    vector<int> hash(128);
    for (char ch : t)
      hash[ch]++;
    while (r < s.size() || allContain(hash)) {
      while (r < s.size() && !allContain(hash))
        hash[s[r++]]--;
      while (l < r && allContain(hash)) {
        if (r - l < minLen) {
          minLen = r - l;
          start = l;
        }
        hash[s[l++]]++;
      }
    }
    return minLen == 0x7fffffff ? "" : s.substr(start, minLen);
  }
};
