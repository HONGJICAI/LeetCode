class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i=0,j=nums.size()-1,n=nums.size();
        while(j>0&&nums[j]<=nums[j-1])--j;
        if(j-1>=0){
            int minIndex=j;
            for(int k=j+1;k<n;++k)
                if(nums[k]>nums[j-1])
                    minIndex=nums[j]<nums[k]?j:k;
            swap(nums[j-1],nums[minIndex]);
            sort(nums.begin()+j,nums.end());
        }
        else
            sort(nums.begin(),nums.end());
    }
};
