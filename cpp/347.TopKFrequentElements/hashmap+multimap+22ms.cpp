class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>hashmap;
        vector<int>res(k);
        multimap<int,int>treemap;
        for(auto num:nums)
            hashmap[num]++;
        for(auto pairs:hashmap)
            treemap.insert(make_pair(pairs.second,pairs.first));
        int i=0;
        for(auto it=treemap.rbegin();i<k;++it)
            res[i++]=it->second;
        return res;
    }
};
