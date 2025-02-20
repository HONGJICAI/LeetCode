class Solution { // 24ms
public:
  int smallestRangeI(vector<int> &A, int K) {
    return max(*max_element(A.begin(), A.end()) -
                   *min_element(A.begin(), A.end()) - 2 * K,
               0);
  }
};
class Solution2 { // 24ms
public:
  int smallestRangeI(vector<int> &A, int K) {
    auto [minIt, maxIt] = minmax_element(A.begin(), A.end());
    return max(*maxIt - *minIt - 2 * K, 0);
  }
};