class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n=nums.size(),maxlen=0;
        for(int i=0;i<n;++i){
            int value=nums[i],pos=i,len=0;
            while(value!=-1){
                nums[pos]=-1;
                pos=value;
                value=nums[value];
                ++len;
            }
            maxlen=max(maxlen,len);
            if(maxlen>n/2)
                return maxlen;
        }
        return maxlen;
    }
};
