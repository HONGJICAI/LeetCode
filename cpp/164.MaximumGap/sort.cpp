int trick = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        sort(begin(nums),end(nums));
        int res=0;
        for(int i=1;i<nums.size();++i)
            res=max(nums[i]-nums[i-1],res);
        return res;
    }
};
