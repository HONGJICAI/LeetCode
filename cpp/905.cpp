// singleScan.cpp
class Solution {
public:
  vector<int> sortArrayByParity(vector<int> &A) {
    int i = 0, j = A.size() - 1;
    while (i <= j)
      if (A[i] & 1)
        swap(A[i], A[j--]);
      else
        ++i;
    return A;
  }
};
