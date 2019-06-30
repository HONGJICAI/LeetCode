class Solution {
//Runtime: 42 ms.Your runtime beats 60.10 % of cpp submissions.
public:
    bool isMatch(string s, string p) {
        int i=0,j=0,star=-1,ii;
        while(i<s.size()){
            bool pNotOver=j<p.size();
            if(pNotOver&&(p[j]=='?'||s[i]==p[j])){
                i++,j++;
            }
            else if(pNotOver&&p[j]=='*'){
                star=++j;
                ii=i;
            }
            else if(star!=-1){
                j=star;
                i=++ii;
            }
            else
                return false;
        }
        return j==p.size()||p.find_first_not_of("*",j)==string::npos;
    }
};
class Solution {
//Runtime: 32 ms, faster than 69.51% of C++ online submissions for Wildcard Matching.
//Memory Usage: 30.2 MB, less than 9.17% of C++ online submissions for Wildcard Matching.
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<int>> f(m + 1, vector<int>(n + 1, 0));
        f[0][0] = 1;
        for (int j = 1; j <= n; j++)
            if('*' == p[j - 1])
                f[0][j] = 1;
            else break;
        int jstart=1;
        for (int i = 1; i <= m; i++)
            for (int j = jstart; j <= n; j++)
                if (p[j - 1] != '*')
                    f[i][j] = f[i - 1][j - 1] && (s[i - 1] == p[j - 1] || '?' == p[j - 1]);
                else{
                    if(f[i-1][j-1] or f[i-1][j] or f[i][j-1]){
                        jstart=j+1;
                        for(int x=i;x<=m;++x)
                            f[x][j]=1;
                    }
                }
        return f[m][n];
    }
};