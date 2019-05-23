class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0,j,len=nums.size();
        if(len==0)return 0;
        for(j=1;j<len;++j)
            if(nums[i]!=nums[j])
                nums[++i]=nums[j];
        return i+1;
    }
};
class Solution { // using stl, 24ms
public:
    int removeDuplicates(vector<int>& nums) {
        return unique(nums.begin(),nums.end())-nums.begin();
    }
};