class NumArray {
//Runtime: 176 ms, faster than 17.29% of C++ online submissions for Range Sum Query - Mutable.
//Memory Usage: 19.1 MB, less than 63.13% of C++ online submissions for Range Sum Query - Mutable.
    vector<int>dp;
    vector<int>m_nums;
public:
    NumArray(vector<int>& nums):m_nums(nums) {
        int len=nums.size();
        if(len==0)return;
        dp.assign(len,nums[0]);
        for(int i=1;i<len;++i)
            dp[i]=dp[i-1]+nums[i];
    }
    
    void update(int i, int val) {
        int temp=i;
        for(int diff=val-m_nums[i];i<dp.size();++i)
            dp[i]+=diff;
        m_nums[temp]=val;
    }
    
    int sumRange(int i, int j) {
        if(i>j)
            swap(i,j);
        if(i==0)
            return dp[j];
        return dp[j]-dp[i-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */
 
class NumArray {
//Runtime: 184 ms, faster than 13.56% of C++ online submissions for Range Sum Query - Mutable.
//Memory Usage: 20 MB, less than 23.38% of C++ online submissions for Range Sum Query - Mutable.
    vector<int>dp;
    vector<int>m_nums;
    map<int,int>cache;
    void doUpdate() {
        auto it=begin(cache),nxt=next(it);
        int diff=0;
        while(it!=end(cache)){
            auto [i,val]=*it;
            diff+=val-m_nums[i];
            m_nums[i]=val;
            for(int idx=i;(nxt==end(cache) or nxt->first!=idx) and idx<dp.size();++idx)
                dp[idx]+=diff;
            ++it;
            nxt=nxt==end(cache)?end(cache):next(nxt);
        }
        cache.clear();
    }
public:
    NumArray(vector<int>& nums):m_nums(nums) {
        int len=nums.size();
        if(len==0)return;
        dp.assign(len,nums[0]);
        for(int i=1;i<len;++i)
            dp[i]=dp[i-1]+nums[i];
    }
    
    void update(int i, int val) {
        cache[i]=val;
    }
    
    int sumRange(int i, int j) {
        if(cache.size())
            doUpdate();
        if(i>j)
            swap(i,j);
        if(i==0)
            return dp[j];
        return dp[j]-dp[i-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */