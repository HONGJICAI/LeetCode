// singleScan-8ms.cpp
class Solution {
public:
  int maxProduct(vector<int> &nums) {
    vector<int> maxPro(nums.size(), nums[0]), minPro(nums.size(), nums[0]);
    auto ret = nums[0];
    for (auto i = 1; i < nums.size(); ++i) {
      maxPro[i] =
          max({nums[i], maxPro[i - 1] * nums[i], minPro[i - 1] * nums[i]});
      minPro[i] =
          min({nums[i], maxPro[i - 1] * nums[i], minPro[i - 1] * nums[i]});
      ret = max({ret, maxPro[i]});
    }
    return ret;
  }
};
// singleScanConstantSpace-8ms.cpp
class Solution {
public:
  int maxProduct(vector<int> &nums) {
    auto maxPro = nums[0], minPro = nums[0], ret = nums[0];
    for (auto i = 1; i < nums.size(); ++i) {
      auto curMaxPro = max({nums[i], nums[i] * maxPro, nums[i] * minPro});
      auto curMinPro = min({nums[i], nums[i] * maxPro, nums[i] * minPro});
      ret = max({ret, curMaxPro});
      maxPro = curMaxPro;
      minPro = curMinPro;
    }
    return ret;
  }
};
