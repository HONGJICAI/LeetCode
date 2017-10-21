/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
    void combine(Interval &dst,Interval &src){
        dst.start=min(dst.start,src.start);
        dst.end=max(dst.end,src.end);
    }
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval>res;
        int i;
        for(i=0;i<intervals.size();++i){
            auto &interval=intervals[i];
            if(newInterval.start<=interval.end)
                break;
            res.push_back(interval);
        }
        for(;i<intervals.size();++i){
            auto &interval=intervals[i];
            if( !(interval.end<newInterval.start) && !(newInterval.end<interval.start))
                combine(newInterval,interval);
            else
                break;
        }
        res.push_back(newInterval);
        for(;i<intervals.size();++i){
            res.push_back(intervals[i]);
        }
        return res;
    }
};
