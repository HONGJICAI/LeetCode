class Solution { // 4ms
public:
  string longestCommonPrefix(vector<string> &strs) {
    if (strs.size() == 0 || strs[0].size() == 0)
      return "";
    string pre = "";
    for (int j = 0; j < strs[0].size(); ++j) {
      char ch = strs[0][j];
      for (int i = 1; i < strs.size(); ++i) {
        if (strs[i].size() <= j || strs[i][j] != ch)
          return pre;
      }
      pre += ch;
    }
    return pre;
  }
};
class Solution2 { // why this takes 0ms?
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 1) return strs[0];
        string ret;
        for (int charN = 0; charN < strs[0].size(); ++charN) {
            for (int wordN = 0; wordN < strs.size(); ++wordN) {
                if (strs[wordN][charN] != strs[0][charN]) {
                    return ret;
                }
            }
            ret += strs[0][charN];
        }
        return ret;
    }
};