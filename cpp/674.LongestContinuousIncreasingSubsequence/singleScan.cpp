class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        int res=1,cur=1;
        for(int i=1;i<nums.size();++i)
            if(nums[i]>nums[i-1])
                ++cur;
            else{
                res=max(res,cur);
                cur=1;
            }
        return max(res,cur);
    }
};
