// hash-12ms.cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 1, l = 1;
        for(bool twice = false;i < nums.size(); ++i) {
            if(nums[i] == nums[i - 1]) {
                if(!twice) {
                    twice = true;
                    nums[l++] = nums[i];
                }
            } else {
                twice = false;                
                nums[l++] = nums[i];
            }
        }
        return l;
    }
};