class Solution {
//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Sort Colors.
//Memory Usage: 8.7 MB, less than 14.74% of C++ online submissions for Sort Colors.
public:
    void sortColors(vector<int>& nums) {
        int i=0,j=nums.size()-1;
        int cur=i;
        while(cur<=j){
            while(cur<=j&&nums[cur]==0)
                swap(nums[cur++],nums[i++]);
            while(cur<=j&&nums[cur]==1)
                ++cur;
            while(cur<=j&&nums[cur]==2)
                swap(nums[cur],nums[j--]);
        }
    }
};