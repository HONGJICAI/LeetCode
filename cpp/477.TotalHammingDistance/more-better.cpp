class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        vector<int> stack(32);
        int res=0;
        for(int i=0; i<nums.size(); i++){
            int tmp=nums[i];
            for(int j=0; j<32; j++){
                stack[j]+=tmp&1;
                tmp=tmp>>1;
            }
        }
        for(int i=0; i<stack.size(); i++)
            res+=stack[i]*(nums.size()-stack[i]);
        return res;
    }
};
