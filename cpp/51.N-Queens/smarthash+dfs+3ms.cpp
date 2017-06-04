class Solution {
    vector<int>flag;
    vector<vector<string>>res;
    vector<string>r;
    int n;
public:
    vector<vector<string>> solveNQueens(int n) {
        string str(n,'.');
        this->n=n;
        r.assign(n,str);
        flag.assign(5*n,1);
        dfs(0);
        return res;
    }
    void dfs(int i){
        if(i==n){
            res.push_back(r);
            return;
        }
        for(int j=0;j<n;++j)
            if(flag[j] && flag[n+i+j] && flag[4*n+i-j]){
                flag[j]=flag[n+i+j]=flag[4*n+i-j]=0;
                r[i][j]='Q';
                dfs(i+1);
                r[i][j]='.';
                flag[j]=flag[n+i+j]=flag[4*n+i-j]=1;
            }
    }
};
