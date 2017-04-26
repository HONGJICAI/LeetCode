class Solution {
    int target;
    vector<vector<int>>res;
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        this->target=target;
        vector<int>cur;
        dfs(candidates,cur,0,0);
        return res;
    }
    void dfs(vector<int>&nums,vector<int>&cur,int i,int sum){
        if(sum==target){
            res.push_back(cur);
            return ;
        }
        if(i==nums.size()||sum>target)
            return;
        cur.push_back(nums[i]);
        dfs(nums,cur,i,sum+nums[i]);
        cur.pop_back();
        dfs(nums,cur,i+1,sum);
    }
};
