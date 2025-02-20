// conciseidea.cpp
class Solution {
public:
  bool checkInclusion(string s1, string s2) {
    int count[26] = {};
    int n1 = s1.size(), n2 = s2.size();
    if (n1 > n2)
      return 0;
    for (int i = 0; i < n1; ++i) {
      ++count[s1[i] - 'a'];
      --count[s2[i] - 'a'];
    }
    if (allZero(count))
      return 1;
    for (int i = n1; i < n2; ++i) {
      --count[s2[i] - 'a'];
      ++count[s2[i - n1] - 'a'];
      if (allZero(count))
        return 1;
    }
    return 0;
  }
  bool allZero(int arr[]) {
    for (int i = 0; i < 26; ++i)
      if (arr[i] != 0)
        return 0;
    return 1;
  }
};
// uglycode.cpp
class Solution2 {
public:
  bool checkInclusion(string s1, string s2) {
    int s1s[26] = {};
    int n = s1.size(), off = 0;
    for (int i = 0; i < n; ++i)
      ++s1s[s1[i] - 'a'];
    for (int i = 0; i + off < s2.size();) {
      if (s1s[s2[i + off] - 'a'] > 0) {
        s1s[s2[i + off] - 'a']--;
        --n;
        ++off;
        if (n == 0)
          return 1;
      } else {
        if (off > 0) {
          s1s[s2[i] - 'a']++;
          --off;
          ++n;
        }
        ++i;
      }
    }
    return 0;
  }
};
