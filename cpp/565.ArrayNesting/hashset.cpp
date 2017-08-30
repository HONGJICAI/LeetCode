class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        unordered_set<int>hashset;
        int len=0,n=nums.size(),maxlen=0;
        for(int i=0;i<n;++i){
            int value=nums[i];
            while(hashset.find(value)==hashset.end()){
                hashset.insert(value);
                value=nums[value];
                ++len;
            }
            maxlen=max(maxlen,len);
            len=0;
        }
        return maxlen;
    }
};
