class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string>res;
        if(nums.size()==0)return res;
        string s=to_string(nums[0]);
        for(int i=1;i<nums.size();++i)
            if(nums[i]!=nums[i-1]+1){
                if(to_string(nums[i-1])!=s)
                    s+="->"+to_string(nums[i-1]);
                res.push_back(s);
                s=to_string(nums[i]);
            }
        if(to_string(nums[nums.size()-1])!=s)
            s+="->"+to_string(nums[nums.size()-1]);
        res.push_back(s);
        return res;
    }
};
