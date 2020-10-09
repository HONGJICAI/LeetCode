// dp.cpp
class Solution {
public:
  int nthUglyNumber(int n) {
    int a = 0, b = 0, c = 0;
    vector<int> nums(n, 1);
    for (int i = 1; i < n; ++i) {
      nums[i] = min(nums[a] * 2, min(nums[b] * 3, nums[c] * 5));
      if (nums[i] == nums[a] * 2)
        ++a;
      if (nums[i] == nums[b] * 3)
        ++b;
      if (nums[i] == nums[c] * 5)
        ++c;
    }
    return nums[n - 1];
  }
};
// set.cpp
class Solution {
public:
  int nthUglyNumber(int n) {
    set<long long int> s;
    s.insert(1);
    auto it = s.begin();
    for (int i = 1; i < n; ++i, ++it) {
      s.insert(*it * 2);
      s.insert(*it * 3);
      s.insert(*it * 5);
    }
    return *it;
  }
};
