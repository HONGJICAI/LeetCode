class Solution {
//Runtime: 20 ms, faster than 71.64% of C++ online submissions for Contains Duplicate III.
//Memory Usage: 10.9 MB, less than 32.96% of C++ online submissions for Contains Duplicate III.
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (k < 1 or t < 0) return false;
        set<int>s;
        for(int i=0;i<nums.size();++i){
            if(i>k)
                s.erase(nums[i-k-1]);
            auto [it,success]=s.insert(nums[i]);
            if(not success)
                return true;
            if(it!=begin(s) and abs((long long)*prev(it)-(long long)*it)<=t)
                return true;
            if(next(it)!=end(s) and abs((long long)*next(it)-(long long)*it)<=t)
                return true;
        }
        return false;
    }
};