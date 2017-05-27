class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int sum=0,n=nums.size(),i,j;
        for(i=0;i<n-1&&nums[i]<=nums[i+1];++i);
        for(j=n-1;i<j&&nums[j]>=nums[j-1];--j);
        if(i--==j++)return 0;
        for(int k=i+1;k<j;++k){
            while(i>=0&&nums[k]<nums[i])
                --i;
            while(j<n&&nums[k]>nums[j])
                ++j;
        }
        return j-i-1;
    }
};
