// dfs.cpp
class Solution {
public:
  vector<string> letterCombinations(string digits) {
    vector<string> letter = {"",    "",    "abc",  "def", "ghi",
                             "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> res;
    if (digits.size() == 0)
      return res;
    dfs(letter, res, digits, "", 0);
    return res;
  }
  void dfs(vector<string> &letter, vector<string> &res, const string &digits,
           string cur, int i) {
    if (i == digits.size()) {
      res.push_back(cur);
      return;
    }
    for (int j = 0; j < letter[digits[i] - '0'].size(); ++j)
      dfs(letter, res, digits, cur + letter[digits[i] - '0'][j], i + 1);
  }
};
class Solution2 {
    vector<string> combine(vector<string> &a, vector<string> &b) {
        vector<string> res;
        for (auto &i : a) {
            for (auto &j : b) {
                res.push_back(i + j);
            }
        }
        return res;
    }
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string> res;
        string[] map = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        res.push_back("");
        for (auto &d : digits) {
            res = combine(res, map[d - '2']);
        }
        return res;
    }
};