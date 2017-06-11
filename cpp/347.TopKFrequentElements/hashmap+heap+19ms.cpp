class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>hashmap;
        for(auto num:nums)
            hashmap[num]++;
        vector< pair<int,int> >res(hashmap.size());
        int i=0;
        for(auto pairs:hashmap)
            res[i++]=pairs;
        vector<int>r(k);
        make_heap(res.begin(),res.end(),[](pair<int,int>&a,pair<int,int>&b){return a.second<b.second;});
        for(i=0;i<k;){
            r[i++]=res.front().first;
            pop_heap(res.begin(),res.end(),[](pair<int,int>&a,pair<int,int>&b){return a.second<b.second;});
            res.pop_back();
        }
        return r;
    }
};
