class Solution { // 0ms
public:
    int numRookCaptures(vector<vector<char>>& b) {
        const vector<pair<int,int>> dir={{1,0},{0,1},{-1,0},{0,-1}};
        int ret=0;
        for (auto i = 0; i < b.size(); ++i)
            for (auto j = 0; j < b[i].size(); ++j)
                if (b[i][j] == 'R'){
                    for(const auto [dx,dy]:dir){
                        int x=i,y=j;
                        while (x >= 0 && x < b.size() && y >= 0 && y < b[x].size() && b[x][y] != 'B'){
                            if (b[x][y] == 'p'){
                                ++ret;
                                break;
                            }
                            x += dx;
                            y += dy;
                        }
                    }
                    break;
                }
        return ret;
    }
};