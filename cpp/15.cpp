class Solution { // sortAndDoublePointer 100ms
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<vector<int>> result;
    for (int i = 0; i < n - 2; ++i) {
      if (i > 0 && nums[i] == nums[i - 1])
        continue;
      for (int low = i + 1, high = n - 1; low < high;) {
        if (int sum = nums[low] + nums[high]; sum == -nums[i]) {
          result.push_back({nums[i], nums[low], nums[high]});
          do {
            ++low;
          } while (low < high && nums[low - 1] == nums[low]);
          do {
            --high;
          } while (low < high && nums[high + 1] == nums[high]);
        } else if (sum > -nums[i])
          --high;
        else
          ++low;
      }
    }
    return result;
  }
};