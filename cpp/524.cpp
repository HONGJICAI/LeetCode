// sort.cpp
class Solution {
public:
  string findLongestWord(string s, vector<string> &d) {
    sort(d.begin(), d.end(), [](string a, string b) {
      return a.size() > b.size() || (a.size() == b.size() && a < b);
    });
    for (int i = 0; i < d.size(); ++i) {
      int start = 0, end = s.size(), j = 0;
      for (; start < end && j < d[i].size(); ++start)
        if (s[start] == d[i][j])
          ++j;
      if (j == d[i].size())
        return d[i];
    }
    return "";
  }
};
