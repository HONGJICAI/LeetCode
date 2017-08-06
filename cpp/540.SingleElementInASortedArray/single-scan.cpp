class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        for(int i=0;i<nums.size();i+=2)
            if(i==nums.size()-1||nums[i]!=nums[i+1])
                return nums[i];
    }
};
