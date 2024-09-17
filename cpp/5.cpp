// center-extend.cpp
class Solution {
  int getPalindromeLength(string &str, int index) {
    int len = 1;
    while (index - len >= 0 && index + len < str.size() &&
           str[index - len] == str[index + len])
      ++len;
    return len - 1;
  } //#b#a#b#a#d#,#c#b#b#d#
public:
  string longestPalindrome(string s) {
    if (s.size() <= 1)
      return s;
    string str = "#";
    for (int i = 0; i < s.size(); ++i, str += "#")
      str.append(1, s[i]);
    int len = 0, cur, index;
    for (int i = 1; i < str.size(); ++i) {
      cur = getPalindromeLength(str, i);
      if (cur > len) {
        len = cur;
        index = i;
      }
    }
    return s.substr(index / 2 - len / 2, len);
  }
};
class Solution {
    bool recursive(const string& s, int i, int j, vector<vector<int>> &dp) {
        if (i >= j) {
            return dp[i][j] = 1;
        }
        if (dp[i][j] != -1) {
            return 0;
        }
        if (s[i] == s[j]) {
            return dp[i][j] = recursive(s, i + 1, j - 1, dp);
        } else {
            return dp[i][j] = 0;
        }
    }
public:
    string longestPalindrome(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1));
        for(int len = s.size(); len > 0; --len) {
            for(int i = 0; i + len <= s.size(); ++i) {
                if(recursive(s, i, i + len - 1, dp)){
                    return s.substr(i, len);
                }
            }
        }
        return "";
    }
};