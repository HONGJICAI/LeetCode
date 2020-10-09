// simple.cpp
class Solution {
public:
  int repeatedStringMatch(string A, string B) {
    if (unordered_set<char>(A.begin(), A.end()).size() <
        unordered_set<char>(B.begin(), B.end()).size())
      return -1;
    int i;
    string temp = A;
    for (i = 1; i < B.size() / A.size() + 3; ++i)
      if (temp.find(B) != string::npos)
        return i;
      else
        temp += A;
    return -1;
  }
};
