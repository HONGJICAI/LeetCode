class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        int i=findNums.size(),j=nums.size();
        vector<int>result(i);
        for(int m=0;m<i;++m)
            result[m]=-1;
        for(int m=0;m<i;++m)
            for(int n=0;n<j;++n)
                if(findNums[m]==nums[n]){
                    for(int k=n+1;k<j;++k)
                        if(nums[k]>findNums[m]){
                            result[m]=nums[k];
                            break;
                        }
                    break;
                }
        return result;
    }
};
