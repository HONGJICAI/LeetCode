// hashset.cpp
class Solution {
public:
  bool isHappy(int n) {
    unordered_set<int> set;
    while (n != 1) {
      int sum = 0;
      while (n > 0) {
        sum += (n % 10) * (n % 10);
        n /= 10;
      }
      n = sum;
      if (set.find(sum) == set.end())
        set.insert(sum);
      else
        return 0;
    }
    return 1;
  }
};
