class Solution {
public:
    bool canPartition(vector<int>& nums) {
        bitset<10001>bits(1);
        int sum=0,n=nums.size();
        for(auto i:nums){
            sum+=i;
            bits|=bits<<i;
        }
        if( (sum&1)==1 )return 0;
        return bits[sum/2];
    }
};