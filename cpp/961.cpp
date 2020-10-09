class Solution { // Runtime: 40 ms, faster than 93.40% of C++ online submissions
                 // for N-Repeated Element in Size 2N Array.
public:
  int repeatedNTimes(vector<int> &A) {
    int i = 0, j = 0;
    while (A[i = rand() % A.size()] != A[j = rand() % A.size()] || i == j)
      ;
    return A[i];
  }
};