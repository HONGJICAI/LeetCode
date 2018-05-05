class Solution {
    int target;
    void dfs(vector<pair<int,int>>&unused,vector<vector<int>>&res,vector<int>&now){
        if(now.size()==target){
            res.push_back(now);
            return;
        }
        for(auto &p:unused){
            if(p.second>0){
                now.push_back(p.first);
                --p.second;
                dfs(unused,res,now);
                ++p.second;
                now.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        target=nums.size();
        unordered_map<int,int>hashmap;
        for(auto num:nums)
            ++hashmap[num];
        vector<pair<int,int>>arr(hashmap.begin(),hashmap.end());
        sort(arr.begin(),arr.end(),[](const pair<int,int>&a,const pair<int,int>&b){return a.first<b.first;});
        vector<vector<int>>res;
        vector<int>now;
        dfs(arr,res,now);
        return res;
    }
};
