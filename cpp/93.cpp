// dfs.cpp
class Solution {
  vector<string> res;

public:
  vector<string> restoreIpAddresses(string s) {
    dfs("", s, 0);
    return res;
  }
  void dfs(string s, string t, int part) {
    if (part == 4 && t == "")
      res.push_back(s);
    if (part == 4)
      return;
    if (s != "")
      s += ".";
    for (int i = 1; i <= 3 && i <= t.size(); ++i) {
      string temp = t.substr(0, i);
      if (stoi(temp) > 255)
        continue;
      if (i > 1 && t[0] == '0')
        break;
      dfs(s + temp, t.substr(i), part + 1);
    }
  }
};
