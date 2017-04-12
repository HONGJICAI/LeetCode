class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1,-1);
        int kind=coins.size();
        if(amount==0)return 0;
        dp[0]=0;
        for(int i=1;i<=amount;++i){
            int min=INT_MAX,index;
            for(int j=0;j<kind;++j)
                if(i-coins[j]>=0){
                    if( dp[ index=i-coins[j] ]>=0)
                        min=dp[index]<min?dp[index]:min;
                }
            dp[i]=min!=INT_MAX?min+1:-1;
        }
        return dp[amount];
    }
};
