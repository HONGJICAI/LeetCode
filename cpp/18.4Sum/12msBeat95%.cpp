class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int i,j,a,b,t,tt,n=nums.size(),sum;
        vector<vector<int>>res;
        sort(nums.begin(),nums.end());
        for(i=0;i<n-3;++i){
            if(i>0&&nums[i]==nums[i-1])continue;
            if(nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target)break;
            if(nums[i]+nums[n-3]+nums[n-2]+nums[n-1]<target) continue;
            t=target-nums[i];
            for(j=i+1;j<n-2;++j){
                if(j>i+1&&nums[j]==nums[j-1])continue;
                if(nums[j]+nums[j+1]+nums[j+2]>t) break;
                if(nums[j]+nums[n-2]+nums[n-1]<t) continue;
                tt=t-nums[j];
                for(a=j+1,b=n-1;a<b;){
                    sum=nums[a]+nums[b];
                    if(sum<tt)
                        ++a;
                    else if(sum>tt)
                        --b;
                    else{
                        res.push_back(vector<int>{nums[i],nums[j],nums[a],nums[b]});
                        do{++a;}while(a<b&&nums[a]==nums[a-1]);
                        do{--b;}while(a<b&&nums[b]==nums[b+1]);
                    }
                }
            }
        }
        return res;
    }
};
