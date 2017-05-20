class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        int *exist=new int[n]();
        for(int i=0;i<n;++i)
            if(nums[i]>0&&nums[i]<=n)
                exist[nums[i]-1]=1;
        for(int i=0;i<n;++i)
            if(exist[i]==0)
                return i+1;
        return n+1;
    }
};
