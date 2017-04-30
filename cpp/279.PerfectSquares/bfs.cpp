class Solution {
public:
    int numSquares(int n) {
        vector<int>step;
        for(int i=1;i*i<=n;++i)
            step.push_back(i*i);
        queue<int>qe;
        vector<bool>visited(n+1,0);
        qe.push(0);
        int level=0,last=1,cur;
        while(visited[n]==0){
            cur=qe.front();
            qe.pop();
            for(int i=0;i<step.size()&&cur+step[i]<=n;++i)
                if(visited[cur+step[i]]==0){
                    qe.push(cur+step[i]);
                    visited[cur+step[i]]=1;
                }
            if(--last==0&&visited[n]==0){
                last+=qe.size();
                ++level;
            }
        }
        return level+1;
    }
};
