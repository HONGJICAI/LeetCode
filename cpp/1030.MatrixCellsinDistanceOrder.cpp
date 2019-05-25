class Solution { //116 ms
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<pair<int,int>>>bucket(R + C);
        for (int r = 0; r < R; r++)
            for (int c = 0; c < C; c++)
                bucket[abs(r-r0)+abs(c-c0)].push_back({r,c});
        vector<vector<int>>ret;
        for(auto &arr:bucket)
            for(auto &pos:arr)
                ret.push_back({pos.first,pos.second});
        return ret;
    }
};