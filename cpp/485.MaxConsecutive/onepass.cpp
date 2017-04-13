class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max=0,count=0;
        for(int i=0;i<nums.size();i++){
            (nums[i]==1)?count++:count=0;
            if(count>max)
            max=count;
        }
        return max;
    }
};
