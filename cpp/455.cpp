// greedy-45ms.cpp
class Solution {
public:
  int findContentChildren(vector<int> &g, vector<int> &s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int count = 0;
    int i = 0, j = 0;
    for (; i < g.size() && j < s.size();)
      if (g[i] <= s[j++]) {
        ++count;
        ++i;
      }
    return count;
  }
};
