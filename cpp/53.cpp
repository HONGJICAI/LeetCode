class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ret = nums[0];
        for (int sum = 0, l = 0; l < nums.size(); ++l) {
            sum += nums[l];
            ret = max(sum, ret);
            if (sum < 0){
                sum = 0;
            }
        }
        return ret;
    }
};