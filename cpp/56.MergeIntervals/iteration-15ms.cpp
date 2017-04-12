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
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(),intervals.end(),[](Interval a,Interval b){return a.start<b.start|| (a.start==b.start&&a.end<b.end);});
        vector<Interval>result;
        if(intervals.size()<1)return result;
        result.push_back(intervals[0]);
        int i=0;
        auto j=intervals.begin();
        for(++j;j!=intervals.end();++j){
            if(result[i].end>=(*j).start){
                result[i].end=max((*j).end,result[i].end);
            }
            else{
                ++i;
                result.push_back(*j);
            }
        }
        return result;
    }
};
