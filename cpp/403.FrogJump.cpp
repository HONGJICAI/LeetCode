class Solution {
//Runtime: 52 ms, faster than 80.66% of C++ online submissions for Frog Jump.
//Memory Usage: 145.6 MB, less than 5.04% of C++ online submissions for Frog Jump.
public:
    bool canCross(vector<int>& stones) {
        vector<vector<int>> visited(stones.size(),vector<int>(stones.size()));
        function<bool(int,int)> dfs=[&stones,&visited,&dfs](int now,int k){
            for (int i=now+1;i<stones.size();++i) {
                int gap = stones[i] - stones[now];
                if (gap < k - 1)
                    continue;
                if (gap > k + 1)
                    return false;
                if (not visited[now][i] and dfs(i, gap))
                    return true;
                else
                    visited[now][i]=1;
            }
            return now==stones.size()-1;
        };
        return dfs(0,0);
    }
};