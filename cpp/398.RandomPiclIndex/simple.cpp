class Solution {
    unordered_map<int,int>hashmap;
    vector<int>nums;
public:
    Solution(vector<int> nums) {
        int n=nums.size();
        for(int i=0;i<n;++i)
            hashmap[ nums[i] ]++;
        this->nums=nums;
    }
    
    int pick(int target) {
        int index=rand()%hashmap[target];
        for(int i=0;i<nums.size();++i)
            if(nums[i]==target)
                if(index--==0)
                    return i;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */
