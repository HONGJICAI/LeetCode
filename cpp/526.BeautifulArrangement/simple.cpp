class Solution {
    int count;
public:
    int countArrangement(int N) {
        vector<int>visited(N+1,0);
        recursion(visited,N,1);
        return count;
    }
    void recursion(vector<int>&visited,int N,int cur){
        if(cur>N){
            ++count;
            return;
        }
        for(int i=1;i<=N;++i)
            if(visited[i]==0&&(i%cur==0||cur%i==0 )){
                visited[i]=1;
                recursion(visited,N,cur+1);
                visited[i]=0;
            }
    }
};
