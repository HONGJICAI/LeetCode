// findTheLaw.cpp
class Solution {
public:
  vector<int> grayCode(int n) {
    if (n < 0)
      return vector<int>();
    vector<int> arr{0};
    for (int i = 0; i < n; ++i) {
      int size = arr.size();
      while (--size >= 0) {
        arr.push_back((1 << i) | arr[size]);
      }
    }
    return arr;
  }
};
// usingMath.cpp
class Solution {
public:
  vector<int> grayCode(int n) {
    if (n == 0)
      return {0};
    // Binary to grey code, num ^ (num >> 1);
    vector<int> res;
    int count = 1 << n;
    for (int i = 0; i < count; i++) {
      res.push_back(i ^ (i >> 1));
    }
    return res;
  }
};
