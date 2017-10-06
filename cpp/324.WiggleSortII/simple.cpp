class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int>copy=nums;
        sort(copy.begin(),copy.end());
        int i=nums.size()-1;
        for(int k=1;k<nums.size();k+=2)
            nums[k]=copy[i--];
        for(int k=0;k<nums.size();k+=2)
            nums[k]=copy[i--];
    }
};
