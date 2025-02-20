// bruteForce.cpp
class Solution {
  bool selfDividing(int num) {
    int remain = num;
    while (remain) {
      int mod = remain % 10;
      if (mod == 0 || num % mod != 0)
        return false;
      remain /= 10;
    }
    return true;
  }

public:
  vector<int> selfDividingNumbers(int left, int right) {
    vector<int> res;
    for (int i = left; i <= right; ++i)
      if (selfDividing(i))
        res.push_back(i);
    return res;
  }
};
