class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int len=nums.size(),i=0;
        for(;nums[i]<target&&i<len;++i);
        return i;
    }
};
