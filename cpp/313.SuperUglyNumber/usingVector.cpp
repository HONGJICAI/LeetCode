class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int>index(primes.size(),0),cache(primes),res(n,1);
        for(int i=1;i<n;++i){
            int minVal=0x7fffffff,offset;
            for(int j=0;j<primes.size();++j)
                if(cache[j]<minVal){
                    minVal=cache[j];
                    offset=j;
                }
            if(minVal<=res[i-1])
                --i;
            else
                res[i]=minVal;
            cache[offset]=res[index[offset]++]*primes[offset];
        }
        return res[n-1];
    }
};
