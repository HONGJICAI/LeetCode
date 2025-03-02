// twoPointer.cpp
class Solution {
public:
  string reverseOnlyLetters(string S) {
    for (int i = 0, j = S.size() - 1; i < j;) {
      while (i < j &&
             !((S[i] >= 'a' && S[i] <= 'z') || (S[i] >= 'A' && S[i] <= 'Z')))
        ++i;
      while (i < j &&
             !((S[j] >= 'a' && S[j] <= 'z') || (S[j] >= 'A' && S[j] <= 'Z')))
        --j;
      swap(S[i++], S[j--]);
    }
    return S;
  }
};
