class Solution {
//Runtime: 224 ms, faster than 38.19% of C++ online submissions for Length of Longest Fibonacci Subsequence.
//Memory Usage: 62.6 MB, less than 7.11% of C++ online submissions for Length of Longest Fibonacci Subsequence.
public:
    int lenLongestFibSubseq(vector<int>& A) {
        unordered_map<int,int> val2idx;
        for(int i=2;i<A.size();++i)
            val2idx[A[i]]=i;
        vector<vector<int>> dp(A.size(),vector<int>(A.size(),0));
        vector<pair<int,int>> st;
        int ret=0;
        for(int i=0;i<A.size();++i){
            for(int j=i+1;j<A.size();++j){
                for(int a=i,b=j;;){
                    if(auto it=val2idx.find(A[a]+A[b]);it!=end(val2idx) and dp[a][b]==0){
                        st.emplace_back(a,b);
                        a=b;
                        b=it->second;
                    }
                    else break;
                }
                while(st.size()){
                    const auto [a,b]=st.back();
                    st.pop_back();
                    dp[a][b]=dp[b][val2idx[A[a]+A[b]]]==0?3:dp[b][val2idx[A[a]+A[b]]]+1;
                    ret=max(ret,dp[a][b]);
                }
            }
        }
        return ret;
    }
};