class Solution {
    struct ugly{
        int base;
        int index;
        int sum;
        bool operator () (ugly&a,ugly&b){
            return a.sum>b.sum;
        }
    };
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        priority_queue<ugly,vector<ugly>,ugly>pq;
        vector<int>res(n,1);
        for(int i=0;i<primes.size();++i)
            pq.push( ugly{primes[i],0,primes[i]} );
        for(int i=1;i<n;++i){
            ugly u=pq.top();
            pq.pop();
            if(u.sum<=res[i-1])
                --i;
            else
                res[i]=u.sum;
            pq.push( ugly{u.base,++u.index,u.base*res[u.index]});
        }
        return res[n-1];
    }
};
