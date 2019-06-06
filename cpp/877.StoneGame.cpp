class Solution {
/*
https://leetcode.com/problems/stone-game/discuss/154610/DP-or-Just-return-true
Alex is first to pick pile.
piles.length is even, and this lead to an interesting fact:
Alex can always pick odd piles or always pick even piles!

For example,
If Alex wants to pick even indexed piles piles[0], piles[2], ....., piles[n-2],
he picks first piles[0], then Lee can pick either piles[1] or piles[n - 1].
Every turn, Alex can always pick even indexed piles and Lee can only pick odd indexed piles.

In the description, we know that sum(piles) is odd.
If sum(piles[even]) > sum(piles[odd]), Alex just picks all evens and wins.
If sum(piles[even]) < sum(piles[odd]), Alex just picks all odds and wins.

So, Alex always defeats Lee in this game.
*/
//Runtime: 4 ms, faster than 95.00% of C++ online submissions for Stone Game.
//Memory Usage: 8.7 MB, less than 58.60% of C++ online submissions for Stone Game.
public:
    bool stoneGame(vector<int>& piles) {
        return true;
    }
};

class Solution { // dp
public:
    bool stoneGame(vector<int>& piles) {
        vector<vector<int>> dp(piles.size(),vector<int>(piles.size(),0));
        for(int i=0;i<piles.size();++i)
            dp[i][i]=piles[i];
        for(int i=1;i<piles.size();++i)
            for(int j=0;j<piles.size()-i;++j)
                dp[j][i+j]=max(piles[j]-dp[j+1][i+j],piles[i+j]-dp[j][i+j-1]);
        return dp[0][piles.size()-1]>0;
    }
};