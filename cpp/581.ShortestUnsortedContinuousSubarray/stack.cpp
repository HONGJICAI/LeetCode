class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        stack<int>st1,st2;
        int sum=0,n=nums.size(),i,j;
        for(i=0;i<n-1&&nums[i]<=nums[i+1];++i)st1.push(nums[i]);
        for(j=n-1;i<j&&nums[j]>=nums[j-1];--j)st2.push(nums[j]);
        if(i==j)return 0;
        for(int k=i;k<=j;++k){
            while(!st1.empty()&&nums[k]<st1.top())
                st1.pop();
            while(!st2.empty()&&nums[k]>st2.top())
                st2.pop();
        }
        return n-st1.size()-st2.size();
    }
};
