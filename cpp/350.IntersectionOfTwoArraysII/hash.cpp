class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>map;
        for(auto i:nums1)
            ++map[i];
        vector<int>result;
        for(auto i:nums2)
            if(map[i]-->0)
                result.push_back(i);
        return result;
    }
};
