class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size(),middle,sum=0;
        if(n<=1)return 0;
        sort(nums.begin(),nums.end());
        middle=nums[n/2];
        for(int i=0;i<n;++i)
            sum+=abs(nums[i]-middle);
        return sum;
    }
};
