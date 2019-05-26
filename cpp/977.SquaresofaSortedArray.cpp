class Solution { // Runtime: 100 ms, faster than 96.05% of C++ online submissions for Squares of a Sorted Array.
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> res;
        int mid = lower_bound(begin(A), end(A), 0) - begin(A);
        for (int r = mid, l = mid - 1; r < A.size() || l >= 0;) {
            int lval=l>=0?A[l]*A[l]:numeric_limits<int>::max();
            int rval=r<A.size()?A[r]*A[r]:numeric_limits<int>::max();
            if(lval<rval){
                res.push_back(lval);
                --l;
            }
            else{
                res.push_back(rval);
                ++r;
            }
        }
        return res;
    }
};