class Solution { // Runtime: 4 ms, faster than 97.52% of C++ online submissions for Two City Scheduling.
public:
    int twoCitySchedCost(vector<vector<int>>& cs, int res = 0) {
        sort(begin(cs), end(cs), [](auto &v1,auto &v2) {
            return (v1[0] - v1[1] < v2[0] - v2[1]);
        });
        for (auto i = 0; i < cs.size() / 2; ++i) 
            res += cs[i][0] + cs[i + cs.size() / 2][1];
        return res;
    }
};