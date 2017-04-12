class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0)return 0;
        int min=prices[0],len=prices.size(),profit=0;
        for(int i=1;i<len;++i)
            if(prices[i]<min)
                min=prices[i];
            else
                profit= prices[i]-min>profit?prices[i]-min:profit;
        return profit;
    }
};
