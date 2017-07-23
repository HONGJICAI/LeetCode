class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double curVal=0;
        for(int i=0;i<k;++i)
            curVal+=nums[i];
        double maxVal=curVal;
        for(int i=k;i<nums.size();++i)
            maxVal=max(curVal+=nums[i]-nums[i-k],maxVal);
        return maxVal/k;
    }
};
