class Solution {
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    }

public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() == 0)
            return 0;
        ranges::sort(intervals, cmp);
        int count = 1, end = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            if (end <= intervals[i][0]) {
                end = intervals[i][1];
                count++;
            }
        }
        return intervals.size() - count;
    }
};