class Solution {
    int memorySearch(unordered_map<int,int>&hashmap,int val){
        auto it=hashmap.find(val);
        if(it==hashmap.end())
            return hashmap[val]=memorySearch(hashmap,val&(val-1))+1;
        return it->second;
    }
public:
    int countPrimeSetBits(int L, int R) {
        int isPrime[21]={0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0};
        unordered_map<int,int>hashmap;
        hashmap[0]=0;
        int count=0;
        for(int i=L;i<=R;++i)
            if(isPrime[memorySearch(hashmap,i)])
                ++count;
        return count;
    }
};
