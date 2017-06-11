class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>hashmap;
        for(auto num:nums)
            hashmap[num]++;
        int i,j,n=nums.size();
        vector<vector<int>>res(n);
        for(auto pairs:hashmap)
            res[pairs.second-1].emplace_back(pairs.first);
        vector<int>r(k);
        for(i=0,j=n-1;i<k;)
            if(res[j].size()>0){
                r[i++]=res[j].back();
                res[j].pop_back();
            }
            else
                --j;
        return r;
    }
};
