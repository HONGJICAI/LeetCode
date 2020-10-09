// 2maps-9ms.cpp
class Solution {
public:
  bool isIsomorphic(string s, string t) {
    int len = s.size(), index1, index2;
    vector<int> hash1(256, INT_MIN);
    vector<int> hash2(256, INT_MIN);
    for (int i = 0; i < len; ++i) {
      index1 = s[i];
      index2 = t[i];
      if (hash1[index1] == INT_MIN) {
        hash1[index1] = t[i];
        if (hash2[index2] != INT_MIN)
          return 0;
        hash2[index2] = s[i];
      }
      if (hash1[index1] != t[i])
        return 0;
      if (hash2[index2] != s[i])
        return 0;
    }
    return 1;
  }
};
