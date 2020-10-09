// hash.cpp
class Solution {
public:
  int fourSumCount(vector<int> &A, vector<int> &B, vector<int> &C,
                   vector<int> &D) {
    unordered_map<int, int> ab;
    int i, j, count = 0;
    for (i = 0; i < A.size(); ++i)
      for (j = 0; j < B.size(); ++j)
        ++ab[A[i] + B[j]];
    for (i = 0; i < C.size(); ++i)
      for (j = 0; j < D.size(); ++j)
        count += ab[-C[i] - D[j]];
    return count;
  }
};
