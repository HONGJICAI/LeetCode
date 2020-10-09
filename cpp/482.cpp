// smarter-6ms.cpp
class Solution {
public:
  string licenseKeyFormatting(string S, int K) {
    string res;
    int count = 0;
    for (auto it = S.rbegin(); it != S.rend(); ++it)
      if (*it != '-') {
        if (count++ == K) {
          count = 1;
          res += '-';
        }
        res += toupper(*it);
      }
    return string(res.rbegin(), res.rend());
  }
};
// stupid-9ms.cpp
class Solution {
public:
  string licenseKeyFormatting(string S, int K) {
    int dashNumber = 0;
    for (auto ch : S)
      if (ch == '-')
        ++dashNumber;
    int charNumber = S.size() - dashNumber;
    int headSize = charNumber % K;
    string res;
    int i = 0, j = 0;
    for (; i < headSize; ++j)
      if (S[j] != '-') {
        res += S[j] >= 'a' && S[j] <= 'z' ? S[j] + 'A' - 'a' : S[j];
        ++i;
      }
    if (headSize)
      res += '-';
    for (i = 0; j < S.size(); ++j) {
      if (S[j] != '-') {
        res += S[j] >= 'a' && S[j] <= 'z' ? S[j] + 'A' - 'a' : S[j];
        if (++i == K) {
          i = 0;
          res += '-';
        }
      }
    }
    if (res.back() == '-')
      res.pop_back();
    return res;
  }
};
