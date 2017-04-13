class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int len=timeSeries.size(),sum=0,gap;
        for(int i=0;i<len-1;i++)
        (gap=timeSeries[i+1]-timeSeries[i])<duration?sum+=gap:sum+=duration;
        if(len>0)
        return sum+duration;
        else
        return 0;
    }
};
