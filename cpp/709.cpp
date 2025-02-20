// usingSTL.cpp
class Solution {
public:
  string toLowerCase(string str) {
    transform(str.begin(), str.end(), str.begin(), ptr_fun<int, int>(tolower));
    return str;
  }
};
