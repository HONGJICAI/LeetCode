class Solution {
public:
    int maxProduct(vector<int>& nums) {
        auto maxPro=nums[0],minPro=nums[0],ret=nums[0];
        for(auto i=1;i<nums.size();++i){
            auto curMaxPro=max({nums[i],nums[i]*maxPro,nums[i]*minPro});
            auto curMinPro=min({nums[i],nums[i]*maxPro,nums[i]*minPro});
            ret=max({ret,curMaxPro});
            maxPro=curMaxPro;
            minPro=curMinPro;
        }
        return ret;
    }
};
