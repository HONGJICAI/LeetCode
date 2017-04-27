class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>cur;
        vector<vector<int>>res;
        dfs(cur,res,nums,0);
        return res;
    }
    void dfs(vector<int>&cur,vector<vector<int>>&res,vector<int>&nums,int i){
        if(nums.size()==i){
            res.push_back(cur);
            return;
        }
        cur.push_back(nums[i]);
        dfs(cur,res,nums,i+1);
        cur.pop_back();
        dfs(cur,res,nums,i+1);
    }
};
