class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_set<int>hashset;
        int n=nums.size();
        for(int i=1;i<=n;++i)
            hashset.insert(i);
        vector<int>res(2);
        for(int num:nums)
            if(hashset.find(num)!=hashset.end())
                hashset.erase(num);
            else
                res[0]=num;
        res[1]=*hashset.begin();
        return res;
    }
};
