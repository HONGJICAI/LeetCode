class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int,int>map;
        int m=wall.size(),n,sum,max=0;
        for(int i=0;i<m;++i){
            n=wall[i].size();
            sum=0;
            for(int j=0;j<n-1;++j)
                ++map[sum+=wall[i][j]];
        }
        for(auto it:map)
            if(it.second>max)
                max=it.second;
        return m-max;
    }
};
