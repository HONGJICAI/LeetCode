class Solution {
    // Function to compare two intervals based on their start times
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    }

public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        // create a map to store the start times and their corresponding indices
        unordered_map<int, int> startMap;
        for (int i = 0; i < intervals.size(); ++i) {
            startMap[intervals[i][0]] = i;
        }
        // Sort intervals by start time
        ranges::sort(intervals, cmp);
        // create a result vector to store the indices of the right intervals
        vector<int> result(intervals.size(), -1);
        // binary search for the right interval for each interval
        for (int i = 0; i < intervals.size(); ++i) {
            auto originIndex = startMap[intervals[i][0]];
            auto target = vector<int>{intervals[i][1], 0};
            auto lower = ranges::lower_bound(intervals, target, cmp);
            if (lower != intervals.end()) {
                int startIndex = lower->at(0);
                result[originIndex] = startMap[startIndex];
            }
        }
        return result;
    }
};