// sort.cpp
class Solution {
public:
  int threeSumClosest(vector<int> &nums, int target) {
    sort(nums.begin(), nums.end());
    int t = 0x7fffffff, j, k, n = nums.size(), s;
    for (int i = 0; i < n; ++i) {
      s = target - nums[i];
      for (j = i + 1, k = n - 1; j < k;) {
        int sum = nums[j] + nums[k];
        if (abs(t) > abs(sum - s))
          t = sum - s;
        if (sum > s)
          k--;
        else if (sum < s)
          ++j;
        else
          return target;
      }
    }
    return target + t;
  }
};
class Solution2 {
public:
    int threeSumClosest(vector<int> nums, int target) {
        sort(nums.begin(), nums.end());
        int ret = 1000000;
        auto find = [&ret, &target](vector<int>& nums, int k){
            int i = k + 1, j = nums.size() - 1;
            while(i<j){
                int sum = nums[i] + nums[j] + nums[k];
                if(abs(sum-target)<abs(ret-target)){
                    ret = sum;
                }
                if (sum > target){
                    --j;
                } else if (sum < target){
                    ++i;
                } else {
                    return;
                }
            }
        };
        for(int k=0;k<nums.size();++k){
            find(nums, k);
            if(ret == target) return ret;
        }
        return ret;
    }
};