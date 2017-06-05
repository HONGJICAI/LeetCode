class Solution {
    vector<int>flag;
    int n,res=0;
public:
    int totalNQueens(int n) {
        this->n=n;
        flag.assign(5*n,1);
        dfs(0);
        return res;
    }
    void dfs(int i){
        if(i==n){
            res++;
            return;
        }
        for(int j=0;j<n;++j)
            if(flag[j] && flag[n+i+j] && flag[4*n+i-j]){
                flag[j]=flag[n+i+j]=flag[4*n+i-j]=0;
                dfs(i+1);
                flag[j]=flag[n+i+j]=flag[4*n+i-j]=1;
            }
    }
};
