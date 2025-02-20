// singleScan.cpp
class Solution {
public:
  vector<vector<int>> flipAndInvertImage(vector<vector<int>> &A) {
    for (auto &arr : A) {
      int i = 0, j = arr.size() - 1;
      for (; i < j; ++i, --j) {
        swap(arr[i], arr[j]);
        arr[i] = !arr[i];
        arr[j] = !arr[j];
      }
      if (i == j)
        arr[i] = !arr[i];
    }
    return A;
  }
};
