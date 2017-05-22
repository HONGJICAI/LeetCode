class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int>res(nums.begin(),nums.end());
        sort(res.begin(),res.end());
        int sum=0,n=nums.size(),i,j;
        for(i=0;i<n&&nums[i]==res[i];++i,++sum);
        for(j=n-1;i<j&&nums[j]==res[j];--j,++sum);
        return n-sum;
    }
};
