class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int res=0;
        for(int i=0;i<32;++i){
            int bitCount=0;
            for(int num:nums)
                bitCount+=(num>>i)&1;
            res+=bitCount*(nums.size()-bitCount);
        }
        return res;
    }
};
