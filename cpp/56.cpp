class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
             [](vector<int>& a, vector<int>& b) {
                 return a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]);
             });
        vector<vector<int>> result = {intervals[0]};
        int i = 0;
        auto j = intervals.begin() + 1;
        for (; j != intervals.end(); ++j) {
            if (result[i][1] >= (*j)[0]) {
                result[i][1] = max((*j)[1], result[i][1]);
            } else {
                ++i;
                result.push_back(*j);
            }
        }
        return result;
    }
};