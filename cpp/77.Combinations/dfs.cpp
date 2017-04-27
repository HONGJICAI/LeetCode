class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int>cur;
        vector<vector<int>>res;
        dfs(cur,res,1,n,k);
        return res;
    }
    void dfs(vector<int>&cur,vector<vector<int>>&res,int i,int n,int k){
        if(cur.size()==k){
            res.push_back(cur);
            return;
        }
        for(;i<=n;++i){
            cur.push_back(i);
            dfs(cur,res,i+1,n,k);
            cur.pop_back();
        }
    }
};
