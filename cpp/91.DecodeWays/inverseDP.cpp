class Solution {
public:
    int numDecodings(string s) {
        int n=s.size();
        if(n==0)return 0;
        vector<int>dp(n+1,0);
        dp[n]=1;
        dp[n-1]=s[n-1]=='0'?0:1;
        for(int i=n-2;i>=0;--i){
            if(s[i]=='0')continue;
            if( stoi(s.substr(i,2)) <=26){
                dp[i]+=dp[i+2];
            }
            dp[i]+=dp[i+1];
        }
        return dp[0];
    }
};
