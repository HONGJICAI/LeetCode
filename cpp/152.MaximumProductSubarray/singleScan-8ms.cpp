class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> maxPro(nums.size(),nums[0]),minPro(nums.size(),nums[0]);
        auto ret=nums[0];
        for(auto i=1;i<nums.size();++i){
            maxPro[i]=max({nums[i],maxPro[i-1]*nums[i],minPro[i-1]*nums[i]});
            minPro[i]=min({nums[i],maxPro[i-1]*nums[i],minPro[i-1]*nums[i]});
            ret=max({ret,maxPro[i]});
        }
        return ret;
    }
};
