class Solution {
//Runtime: 72 ms, faster than 75.46% of C++ online submissions for Lexicographical Numbers.
//Memory Usage: 11 MB, less than 94.00% of C++ online submissions for Lexicographical Numbers.
public:
    vector<int> lexicalOrder(int n) {
        if(n<=0)
            return {};
        vector<int>ret(n);
        int i=0;
        function<void(int)>dfs=[&](int now){
            ret[i++]=now;
            if(now*10<=n)
                dfs(now*10);
            if(now+1<=n and now%10<9)
                dfs(now+1);
        };
        dfs(1);
        return ret;
    }
};