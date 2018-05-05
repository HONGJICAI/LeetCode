class Solution {
public:
    vector<int> grayCode(int n) {
        if (n==0)
            return {0};
        //Binary to grey code, num ^ (num >> 1);
        vector<int> res;
        int count=1<<n;
        for (int i=0; i<count; i++) {
            res.push_back(i ^ (i >> 1));  
        }
        return res;
    }
};
