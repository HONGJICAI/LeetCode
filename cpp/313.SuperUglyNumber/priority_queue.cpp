class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        priority_queue<long long int,vector<long long int>,greater<int>>pq;
        pq.push(1);
        long long int last=-1,temp;
        while(n){
            long long int cur=pq.top();
            pq.pop();
            if(last!=cur){
                last=cur;
                --n;
                for(int num:primes)
                    if( (temp=num*cur)<=(long long int)0x7fffffff)
                        pq.push(temp);
            }
        }
        return last;
    }
};
