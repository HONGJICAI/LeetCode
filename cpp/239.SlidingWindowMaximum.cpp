class Solution {
//Runtime: 60 ms, faster than 67.00% of C++ online submissions for Sliding Window Maximum.
//Memory Usage: 13.4 MB, less than 27.55% of C++ online submissions for Sliding Window Maximum.
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(k>=nums.size()&&nums.size())
            return {*max_element(begin(nums),end(nums))};
        if(k<=0)
            return {}; 
        deque<int> dq;
        vector<int>ret;
        for(int i=0;i<nums.size();++i){
            if(dq.empty() or dq.back()>=nums[i])
                dq.push_back(nums[i]);
            else{
                while(dq.size() and dq.back()<nums[i])
                    dq.pop_back();
                dq.push_back(nums[i]);                
            }
            if(i+1>=k){
                ret.push_back(dq.front());
                if(nums[i+1-k]==dq.front())
                    dq.pop_front();
            }
        }
        return ret;
    }
};