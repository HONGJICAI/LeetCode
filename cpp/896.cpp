class Solution { // Runtime: 88 ms, faster than 42.76% of C++ online submissions
                 // for Monotonic Array.
public:
  bool isMonotonic(vector<int> A) {
    bool inc = true, dec = true;
    for (int i = 1; i < A.size(); ++i) {
      inc &= A[i - 1] <= A[i];
      dec &= A[i - 1] >= A[i];
    }
    return inc || dec;
  }
};