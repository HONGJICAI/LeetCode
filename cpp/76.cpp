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
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> tMap;
        for (char c : t)
            tMap[c]++;
        int i = 0;
        string res = s + ' ';
        while(i < s.size() && tMap.find(s[i]) == tMap.end())
            ++i;
        auto moveLeftWindUtilNotMatch = [&tMap, &s](int &i, const int j) {
            for (;i <= j; ++i) {
                if (auto it = tMap.find(s[i]); it != tMap.end()) {
                    if (++it->second > 0) {
                        ++i;
                        break;
                    }
                }
            }
        };
        for (int j = i, matchCnt = 0; j < s.size(); ++j) {
            if (tMap.find(s[j]) != tMap.end() && --tMap[s[j]] == 0) {
                matchCnt++;
                if (matchCnt == tMap.size()) {
                    moveLeftWindUtilNotMatch(i, j);
                    matchCnt--;                    
                    if (j - i + 2 < res.length()) {
                        res = s.substr(i - 1, j - i + 2);
                    }
                }
            }
        }
        return res.size() > s.size() ? "" : res;
    }
};