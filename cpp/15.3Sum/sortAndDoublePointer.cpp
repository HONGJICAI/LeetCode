class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>>result;
        for(int i=0;i<n-2;++i){
            if(i>0&&nums[i]==nums[i-1])continue;
            int low=i+1,high=n-1;
            while(low<high){
                int sum=nums[low]+nums[high];
                if(sum==-nums[i]){
                    vector<int>res(3);
                    res[0]=nums[i];
                    res[1]=nums[low];
                    res[2]=nums[high];
                    result.push_back(res);
                    do{++low;}while(low<high&&nums[low-1]==nums[low]);
                    do{--high;}while(low<high&&nums[high+1]==nums[high]);
                }
                else if(sum>-nums[i])
                    --high;
                else
                    ++low;
            }
        }
        return result;
    }
};
