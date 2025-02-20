// myidea.cpp
class Solution {
public:
  vector<int> findAnagrams(string s, string p) {
    vector<int> res;
    vector<int> letter(26, 0);
    int total = p.size(), start = 0;
    for (int i = 0; i < p.size(); ++i)
      letter[p[i] - 'a']++;
    for (int i = 0; i < s.size();)
      if (letter[s[i] - 'a'] > 0) {
        letter[s[i] - 'a']--;
        ++i;
        if (--total == 0) {
          total = 1;
          letter[s[start] - 'a']++;
          res.push_back(start++);
        }
      } else {
        if (i > start) {
          letter[s[start] - 'a']++;
          start++;
          total++;
        } else {
          ++i;
          ++start;
        }
      }
    return res;
  }
};
