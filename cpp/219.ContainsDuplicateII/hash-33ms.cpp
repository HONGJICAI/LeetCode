class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int>map;
        int len=nums.size();
        for(int i=0;i<len;++i)
            if(map.find(nums[i])!=map.end()){
                if(abs(i-map[nums[i]])<=k)
                    return 1;
                map[nums[i]]=i;
            }
            else
                map[nums[i]]=i;
        return 0;
    }
};
