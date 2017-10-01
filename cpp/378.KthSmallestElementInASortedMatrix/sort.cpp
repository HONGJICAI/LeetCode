class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        multiset<int>res;
        for(auto &arr:matrix)
            res.insert(arr.begin(),arr.end());
        auto it=res.begin();
        for(int i=1;i<k;++i)
            ++it;
        return *it;
    }
};
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int>res;
        for(auto &arr:matrix)
            res.insert(res.end(),arr.begin(),arr.end());
        sort(res.begin(),res.end());
        return res[k-1];
    }
};
